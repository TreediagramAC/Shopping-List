
#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;using std::stringstream; using std::istringstream;
#include<vector>
using std::vector;
#include<map>
using std::map;
#include<string>
using std::string;using std::stol;using std::to_string;
#include<algorithm>
using std::sort;
#include<iomanip>
using std::setprecision;
using std::fixed;


/*
Build a basic struct to store all the related infos
The operate object in this programm is each line after shop's name and shop's location
*/
struct Item{
   string store;
   string location;
   string items;
   long quantity ;
   double price ;
   Item (string s,string loc,string i,long q, double p) {
     store = s;location = loc;items = i;quantity = q;price = p;}
};

/*
Build a basic struct to store all the related infos in shopping list
The operate object in this programm is each line for shoplist item's name and shoplist item's quantity
*/
struct Shopitem{
  string name;
  long need;
  Shopitem(string n, long q){
    name = n; need = q;
  }
};

/*Originally want to build a function to erase $ in price element.
string change(string text) {
    for(int i = 0; i < text.length(); i++){
      if(text[i] == '$') {
      text[i] = ' ';
      }
    }
    return text;
}
*/

/*
This function is builded to get the number of eash item in shopping list.
*/
long extractnum(string line){
  stringstream result;
  long num;
  result << line;
  result >> num;
  return num;
}

/*
This function is builded to get the name of eash item in shopping list.
*/
string extractname(string line,long num){
  string result;
  long length;
  length = to_string(num).size();
  result = line.substr(length+1, line.length()-length);
  return result;
}

/*
This function is used to split line by provided char to get
items name quanity and price).
It was getted from CSE232 lecture &video:
https://www.cse.msu.edu/~cse232/Lectures/Week05.html
*/
void split(const string &s, vector<string> &elems, char sep) {
    istringstream iss(s);
    string item;
    while(getline(iss, item, sep))
      if (item[0]=='$')
        elems.push_back(item.substr(1, item.size()-1));
      else{
        elems.push_back(item);
      }
}

int main(){
  string line;
  long storenum;
  string storename; string storelocation;
  map<string,long> itemquanity;
  vector<string> storenamev;
  vector<string> storeitemv;
  vector<long> storeitemvn;
  vector<Item> shopitem;
  getline(cin,line);
  storenum = extractnum(line);
  vector <string> itemsplit;
  cout << fixed<<setprecision(2);
  for (int row = 0;row<storenum;row ++){
    getline(cin,line);
    storename = line;
    storenamev.push_back(storename);
    getline(cin,line);
    storelocation = line;
    while(getline(cin,line)){
      if (line.empty() == true){
        break;
      }
      else{
        split(line,itemsplit,',');
        Item item(storename,storelocation,itemsplit[0],stol(itemsplit[1]),
        stod(itemsplit[2]));
        shopitem.push_back(item);
        itemquanity[item.items] += item.quantity;
        storeitemv.push_back(itemsplit[0]);
        itemsplit.clear();
      }
    }
    storeitemvn.push_back(storeitemv.size());
    storeitemv.clear();
  }


  cout<<"Store Related Infomation (ordered by in-file order):"<<endl;
  cout<<"There are "<<storenum<<" store(s)."<<endl;
  for(long i=0; i < storenamev.size();i++){
    cout<<storenamev[i]<<" has "<<storeitemvn[i]<<" distinct items."<<endl;
  }
  cout<<endl;
  cout<<"Item Related Infomation (ordered alphabetically):"<<endl;
  cout<<"There are "<<itemquanity.size()<<" distinct item(s) avaliable for purchase."<<endl;

  /*
  Get the following code from https://stackoverflow.com/questions/10750057/how-to-print-out-the-contents-of-a-vector
  This part of code is used to display every keys and their values in a map.
  */
  ///Start
  map<string,long>::key_compare itemkey = itemquanity.key_comp();
  string highest = itemquanity.rbegin()->first;     // key value of last element
  map<string,long>::iterator it = itemquanity.begin();
  do {
    cout << "There are "<<it->second <<" "<< it->first << "(s)."<<endl;
  } while ( itemkey((*it++).first, highest) );

  cout << endl;
  ///End

  /*
  This function is used to sort map by their element's attribute: price
  It was getted from CSE232 lecture &video:
  https://www.cse.msu.edu/~cse232/Lectures/Week03.html
  */

  sort(shopitem.begin(),
    shopitem.end(),
    [](const Item& i1, const Item& i2){
    return i1.price<i2.price;
    }
  );

  cout<<"Shopping:"<<endl;

/*The code opinion is coop and disscus with Yu Han
 But code logic is different.
 */
  getline(cin,line);
  long needitem = extractnum(line);
  string itemname;
  vector<string> buy_store;
  vector<long> buy_item;
  vector<string> buy_location;
  double totalprice = 0;
  for (int rows = 0;rows<needitem;rows ++){
    getline(cin,line);
    long finalnum = extractnum(line);
    long needitemn = finalnum;
    double itemprice = 0;
    itemname = extractname(line, needitemn);
    Shopitem need(itemname,needitemn);
    for (auto i : shopitem){
      if(need.name == i.items){
        if (needitemn > i.quantity){
            itemprice += i.quantity * i.price;
            needitemn -= i.quantity;
            buy_item.push_back(i.quantity);
            buy_location.push_back(i.location);
            buy_store.push_back(i.store);
        }
        else{
          itemprice += needitemn * i.price;
          buy_item.push_back(needitemn);
          buy_location.push_back(i.location);
          buy_store.push_back(i.store);
          needitemn = 0;
          }
        }
      }
          cout<<"Trying to order "<<finalnum<<" "<<itemname<<"(s)."<<endl;
          long storesell = 0;
          for(auto i: shopitem){
            if(itemname == i.items){
              storesell += 1;
            }
          }
          cout << storesell <<" store(s) sell "<<itemname<<"."<<endl;
          cout << "Total price: $"<<itemprice<<endl;
          totalprice += itemprice;
          for (long i=0;i<buy_item.size();i++){
            if(buy_item[i] != 0){
              cout<<"Order "<<buy_item[i]<<" from "<<buy_store[i]<<" in "<<buy_location[i]<<endl;
            }
          }
          cout<<endl;
          buy_item.clear();
          buy_location.clear();
          buy_store.clear();
        }
    cout<<"Be sure to bring $"<<totalprice<<" when you leave for the stores."<<endl;
}
