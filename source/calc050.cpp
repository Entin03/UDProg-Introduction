#include "std_lib_facilities.h"

constexpr char number ='8';
constexpr char result ='=';
constexpr char quit ='x';
constexpr char print =';';
constexpr char let = 'L';
constexpr char name ='a';
constexpr char square_root ='@';

const string declkey = "let";
const string sqrtkey = "sqrt";

  double expression();
  
  class Variable
  {
   public:
      string name;
      double value;
  };
  
  vector<Variable> var_table;
  
  bool is_declared(string var)
  {
    for (const auto& v : var_table)
      if (v.name == var) return true;
    return false;
  }
  
  double define_name(string var, double val)
  {
    if (is_declared(var)) error("Variable is declared: ", var); 
      var_table.push_back(Variable{var,val});
    return val;
  }
  
  double get_value(string s)
  {
    for (const auto& v: var_table)
      if (v.name == s) return v.value;
     error("get: variable not defined");
  }
  
  void set_value(string s, double d)
  {
    for (auto& v : var_table)
      if (v.name == s)
      {
         v.value = d;
         return;
      }
    error("set: variable not defined");
  }

  class Token {
  public:
     char kind;
     double value;
     string name;
     Token (): kind(0) {}
     Token (char ch): kind(ch), value(0) {}
     Token (char ch, double val): kind(ch), value(val) {}
     Token (char ch, string n): kind(ch), name(n) {}
  };
  
  class Token_stream {
  public:
     Token_stream();
     Token get();
     void putback(Token t);
     void ignore(char c);
  private:
     bool full;
     Token buffer;   
  };
  
  Token_stream::Token_stream(): full(false), buffer(0) {}

 void Token_stream::putback(Token t)
{
 
 if (full) error("Token_stream buffer full");
 buffer = t;
 full = true;
 
}

  Token Token_stream::get()
  { 
     if (full)
     {
       full = false;
       return buffer;
     }
  
     char ch;
     cin >> ch;
     
     switch (ch){
        case quit:
        case '=':
        case print:
        case '+':
        case '-':
        case '(':
        case ')':
        case '/':
        case '*':
        case '%':
        
        return Token(ch);
        
        case '.':
        case '1': case '2': case '3':
        case '4': case '5': case '6':
        case '7': case '8': case '9': case '0':{
        
        cin.putback(ch);
        double val=0;
        cin >> val;
        
        return Token(number,val);
        }
        
        default:
        {
          if (isalpha(ch)){
             string s;
             s += ch;
             while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;
             cin.putback(ch);
             
             if (s == declkey) return Token{let};
             else if (s == sqrtkey) 
                return Token{square_root};
             else if (is_declared(s))
                return Token(number, get_value(s));
             return Token{name,s};
        }            
        error("Bad token");
        } 
    }      
  }

void Token_stream::ignore(char c)
{
  if (full && c == buffer.kind)
  {
    full = false;
    return;
  }

  full = false;
  
  char ch = 0;
  while (cin>>ch)
    if (ch == c) return;
}
  
  Token_stream ts;
  
  double calc_sqrt()
  {
    char ch;
    if (cin.get(ch) && ch != '(') error ("'(' expexted ");
    cin.putback(ch);
    
    double d = expression(); 
    if (d < 0) error ("sqrt: negative value");
    
    return sqrt(d);
  }
  
  double primary()
  {
    Token t = ts.get();
    switch (t.kind){
      case '(':
      {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
        return d;
      }
      case number:      
        return t.value;    
        
      case '-':
        return - primary();
        
      case '+':  
        return primary();
        
      case square_root: //qrt(9); sqrt(9+6); sqrt(3*x);
        return calc_sqrt();
        
      default:
        error("Primary expected"); return 0;
    }
  }
  
  double term()
  {
    double left=primary();
    Token t = ts.get();
    
    while (true)
    {
      switch (t.kind){
        case '*':
          left *= primary();
          t = ts.get();
          break;
        case '/':{
         double d = primary();
         if (d == 0) error(" Divide by zero ");
          left /= d;
          t=ts.get();
          break;
        }
        case '%':
        {
         /* int i1 = narrow_cast<int> (left);
          int i2 = narrow_cast<int>(primary());
          if (i2 == 0) error("%:zero divider");
          left = i1 % i2;
          t = ts.get();
          break;     
          */     
       
          double d=primary();
          if (d==0) error("%: zero divider");
          left = fmod(left, d);
          t = ts.get();
          break;
        
        }
        /*  left modulo= primary();
          t = get_token();
          break; */
        default:
          ts.putback(t);
          return left;
      
      
      }
    }
  
  }
  
  double expression() 
  {
    double left= term();
    Token t = ts.get();
    
    while (true)
    {
     switch (t.kind){
       case '+':
         left += term();
         t = ts.get();
         break;
       case '-':
         left -= term();
         t = ts.get();
         break;
       default: 
         ts.putback(t);
         return left;
    }
    }
  
  }
  
void clean_up_mess()
{ 
  ts.ignore(print);  
}

double declaration()
 {
   Token t = ts.get();
   if (t.kind != name) error("Name expected in declaration");
   string var_name = t.name;
   
   Token t2 = ts.get();
   if (t2.kind != '=') error("= expected in declaration");
   
   double d = expression();
   define_name(var_name, d);
   return d;
   
 }

 double statement()
 {
   Token t = ts.get();
   switch (t.kind)
   {
     case let:
       return declaration();
     default:
       ts.putback(t);
       expression();  
   }
 }

 
void calculate(){

  
  while (cin)
 try  {
    Token t = ts.get();
    
    while(t.kind == print) t = ts.get();
    if (t.kind ==quit) return;
    
    ts.putback(t); 
    cout << statement() << endl;
    
    /*if (t.kind == quit) break;
    if (t.kind == result)
      cout << val << "\n";
    else
      ts.putback(t);
     val = expression();
     */
  } catch (exception& e) {
     cerr << e.what() << endl;
     clean_up_mess();
     
  }

}

int main()
try{
  cout << "Welcome to our simple calculator.\nPlease enter expressions using floating-point numbers.\nYou can use the following operators: '+','-','*','/','(',')'\nUse '=' to print and 'x' to quit the calculator.\n";

  define_name("pi", 3.14159);
  define_name("e",2.71828);
  double val = 0;

 calculate();
 
   return 0;

}
catch (exception& e){
  cerr << e.what() << endl;
  return 1;
}

catch (...){
  cerr << "exeption\n";
  return 2;
}
