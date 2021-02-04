#include<bits/stdc++.h>
using namespace std;

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif



    char ct;

    string f;
    string operators = "+-*/%=";

    while(cin >> ct){
        if(ct==' ')
            continue;
        f+=ct;
    }

    unordered_map<char,bool> mp;
    mp.clear();

    for(int i=0;i<operators.length();i++){
        mp[operators[i]] = 1;
    }

    for(auto i : mp){
        cerr<<i.first<<" ";
    }
    cerr<<"\n";

    bool validExp = 1;

    map<string, int> identifiers;
    map<char, bool> oprs;
    identifiers.clear();
    oprs.clear();

    string buff = "";
    int ctr = 0;

    stack<string> expression;

    cerr<<"length of stringstream input "<<f.length()<<"\n\n";
    cerr<<"buffer log: \n";

    for(int i=0;i<f.length();i++){

        cerr<<buff<<"\n";

        if(f[i] == '\n' && validExp == 1){
            validExp = 1;
            if(buff != ""){
                identifiers[buff] = ctr;
                string temp = "id";
                temp += char('0' + ctr);
                expression.push(temp);
                ctr += 1;
                buff="";
            }

        }
        else if(f[i] == '\n' && validExp == 0){
            validExp = 0;
            if(buff != ""){
                identifiers[buff] = ctr;
                string temp = "id";
                temp += char('0' + ctr);
                expression.push(temp);
                ctr += 1;
                buff="";
            }
            
        }



        else if(mp.find(f[i]) != mp.end()){
            if(buff !=""){
                identifiers[buff] = ctr;
                string temp = "id";
                temp += char('0' + ctr);
                expression.push(temp);
                ctr += 1;
            }

            validExp = 0;
            string temp = "";
            temp += f[i];
            expression.push(temp);
            oprs[f[i]] = 1;
            buff="";
            
        }


        else{
            buff += f[i];
        }

    }

    if(buff != ""){
        identifiers[buff] = ctr;
        string temp = "id";
        temp += char('0' + ctr);
        expression.push(temp);
        ctr += 1;
        buff="";
        validExp = 1;
    }

    if(!validExp){
        cout<<"Invalid Expression !";
        return 0;
    }

    cout<<"operators found :\n";

    for(auto i : oprs){
        cout<<i.first<<" ";
    }

    cout<<"\n\nidentifiers table :\n";
    
    for(auto i : identifiers){
        cout<<i.first<<"    id"<<i.second<<"\n";
    }       

    vector<string> detectedExp;
    while( !expression.empty() ){
        detectedExp.push_back(expression.top());
        expression.pop();
    }

    reverse(detectedExp.begin(), detectedExp.end());
    
    cout<<"\ndetected Expression : \n";
    for(auto i : detectedExp){
        cout<<i;
    }
    return 0;


}