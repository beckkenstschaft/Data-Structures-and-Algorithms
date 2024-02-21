#include<iostream>
#include<unordered_map>
using namespace std;

void insert_map(unordered_map<char, int> &map, char key, int value){
    map[key] = value;
}

void update_map(unordered_map<char, int> &map, char key, int value){
    for(auto &i : map){
        if(i.first == key){
            i.second = value;
            return;
        }
    }
}

bool find_map(unordered_map<char, int> &map, char key){
    return map.find(key) != map.end();
}

int show_data(unordered_map<char, int> &map){
    for(auto &i : map){
        cout<<i.first<<"->"<<i.second<<endl;
    }
    return 0;
}

int main(){
    unordered_map<char, int> map;
    
    int ch;
    
    do{
        cout<<"ENTER CHOICE : ";
        cin>>ch;

        if(ch == 1){
            cout<<"INSERT"<<endl;
            
            char key;
            int value;
            
            cout<<"ENTER KEY : ";
            cin>>key;
            
            cout<<"ENTER VALUE : ";
            cin>>value;
            
            insert_map(map, key, value);
        }

        else if(ch == 2){
            cout<<"UPDATE"<<endl;
            
            char key;
            int value;
            
            cout<<"ENTER KEY : ";
            cin>>key;
            
            cout<<"ENTER NEW VALUE : ";
            cin>>value;
            
            update_map(map, key, value);
        }

        else if(ch == 3){
            cout<<"FIND"<<endl;
            char key;
            
            cout<<"ENTER KEY : ";
            cin>>key;
            
            bool result = find_map(map, key);
            cout<<"RESULT : "<<result<<endl;
        }

        else if(ch == 4){
            show_data(map);
        }
    } 
    while(ch != 0);
    return 0;
}