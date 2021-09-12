#include<iostream>
#include<fstream>

using namespace std;

int main(){
    int command;
    string Username,UserPassword,Inname,Inpassword,name,password;

    cout<<"\n\nLOGIN SYSTEM\n";

    cout<<"\n------------- COMMANDS -------------\n";
    cout<<"1 : Login"<<endl<<"2 : Registration"<<endl<<"3 : Exit"<<endl;
    cout<<"-----------------------------------\n\n";


    while(1){

        cout<<"Enter Command Number : ";
        cin>>command;

        if(command==3){
            break;
        }
        else if(command==2){

            ofstream file("registration.txt");

            if(!file.is_open()){
                cout<<"File can not open\n";
                cout<<"***** System Failure *****\n";
                return 0;
            }

            cout<<"\n---------- Enter Registration Details ----------\n";
            cout<<"Enter Username : ";
            cin>>Username;
            cout<<"Enter User Password : ";
            cin>>UserPassword;
            while(1){

                bool UC_check=false, LC_check=false, Num_check=false, Sym_check=false;

                for(int i=0; i<UserPassword.size(); i++){
                    if(UserPassword[i]>=48 && UserPassword[i]<=57){
                        Num_check = true;
                    }
                    if(UserPassword[i]>=65 && UserPassword[i]<=90){
                        UC_check = true;
                    }
                    if(UserPassword[i]>=97 && UserPassword[i]<=122){
                        LC_check = true;
                    }
                    if((UserPassword[i]>=32 && UserPassword[i]<=47) || (UserPassword[i]>=58 && UserPassword[i]<=64) || (UserPassword[i]>=91 && UserPassword[i]<=96) || (UserPassword[i]>=123 && UserPassword[i]<=126)){
                        Sym_check = true;
                    }
                }

                if(!(UC_check && LC_check && Num_check && Sym_check)){
                    cout<<"!!! Password should contain Uppercase letters, Lowercase letters, Numbers and Symbols !!!!!\n";
                    cout<<"Enter User Password : ";
                    cin>>UserPassword;
                }
                else if(UserPassword.size()<8){
                    cout<<"Password should contain atleast 8 characters\n";
                    cout<<"Enter User Password : ";
                    cin>>UserPassword;
                }else{
                    break;
                }
            }
            cout<<"---------------------------------------------------\n\n";

            // putting the input name and password in registration.txt 
            file<<Username;
            file<<"\n";
            file<<UserPassword;
            file.close();
        }
        else if(command==1){
            bool login=false;
            ifstream f("registration.txt");

            if(!f.is_open()){
                cout<<"File can not open\n";
                cout<<"***** System Failure *****\n";
                return 0;
            }

            getline(f, name, '\n');
            getline(f, password, '\n');
            f.close();

            while(1){

                cout<<"\n---------- Login Details ----------\n";
                cout<<"Username : ";
                cin>>Inname;
                cout<<"Password : ";
                cin>>Inpassword;
                cout<<"-----------------------------------\n";

                if(Inname==name && Inpassword==password){
                    cout<<"-*-*-*- Login Successfully -*-*-*-";
                    cout<<"\nWelcome, "<<Inname;
                    cout<<"\n\n$$$$$$$$$$ Loading Application $$$$$$$$$$......\n\n";
                    cout<<"\n";
                    login=true;
                    break;
                }
                cout<<"!!!!!  Either incorrect name or incorrect password  !!!!!\n";
            }
            if(login){
                break;
            }
        }
        else{
            cout<<"!!!!! Wrong Command !!!!!\n";
            cout<<"\nEnter Correct Command\n";
        }
    }

    return 0;
}