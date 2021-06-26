#include<bits/stdc++.h>
using namespace std;
void  Student_pass();
void Stdnt_login();
int main();
/*                                                             #################################
                                                                #          This Part For Login Boolean Function     #
                                                                #################################
*/
bool IsLoggedIn()
{
    string username, password, usrnm, pss;


    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t       ##############################################################"<<endl;
    cout<<endl;
    cout<<"\t\t\t           For Login Please Enter Your Valid Username And Password"<<endl;
    cout<<endl;
    cout<<"\t\t\t       ##############################################################"<<endl;
    cout<<endl<<endl;

    cout<<"\t\t\t\t\t\t\tUserName :";
    cin>>username;
    cout<<"\t\t\t\t\t\t\tPassWord: ";
    cin>>password;
    cout<<endl;
    ifstream readFile;
    string file =  username + ".txt";
    readFile.open(file.c_str());
    getline(readFile, usrnm);
    getline(readFile,pss);
    readFile.close();

    if(usrnm == username && pss == password)
    {
        return true;
    }
    else
        return false;


}
//---------------------------------------------------------------------------End Of  Bool IsLogin  Part--------------------------------------------------------------------------------------------



/*                                                             #################################
                                                                #          This Part For After_Registration              #
                                                                #################################
*/
void After_reg()
{

    int ch;
    cout<<"\t\t\t\t\t\t\t 1.Login"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t 2.Main Menu"<<endl<<endl;
    cout<<"\t\t\t\t\t \t\t Enter Choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        system("cls");
        Stdnt_login();
        break;
    case 2:
        system("cls");
        main();
        break;
    default:
        cout<<"\n\t\t\t\t\t           Invalid Choice!\n\n\t\t\t\           For Choice Again Enter 1 Or Enter 0 For Main Menu."<<endl;
        int c;
        cout<<"\n\t\t\t\t\t           Enter 1/0: ";
        cin>>c;
        switch(c)
        {
        case 1:
            After_reg();
            break;
        case 2:
            break;
        }

    }
}
//---------------------------------------------------------------------------End Of  After Registration  Part--------------------------------------------------------------------------------------------





/*                                                             #################################
                                                                #          This Part For Student_Registration         #
                                                                #################################
*/
void Stdnt_reg()
{

    string username,password;
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t      ####################################################################"<<endl;
    cout<<endl;
    cout<<"\t\t\t        For Registration Please Enter Your Valid Username And Password"<<endl;
    cout<<endl;
    cout<<"\t\t\t      ####################################################################"<<endl;
    cout<<endl<<endl;


    cout<<"\t\t\t\t\t\t\tUserName : ";
    cin>>username;
    cout<<"\t\t\t\t\t\t\tPassWord: ";
    cin>>password;
    cout<<endl;
    /*
    save username and password as a txt file
    file save as user's username.
    */
    ofstream file;//("database.txt",ios::app);
    string fileName =  username + ".txt";
    file.open(fileName.c_str());

    //username and password saving format
    file<< username << endl <<password;
    file.close();
    cout<<"\t\t\t\t\t\t   Registration successfull"<<endl<<endl;

    After_reg();

}
//-----------------------------------------------------------------    ----End Of Student Registration Part--------------------------------------------------------------------------------------------



/*                                                             #################################
                                                                #          This Part For Student_Logi n                    #
                                                                #################################
*/
void Stdnt_login()
{

    bool status = IsLoggedIn();

    if(status)
    {
        cout<<"\t\t\t\t\t\t   Successfulluy Logged In"<<endl;

        system("cls");
        //Student_Panel();
    }
    else
    {
        cout<<"\t\t\t\t\t\tInvalid Username  Or Password"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t1.Try Again"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t2.Go to Main Menu"<<endl<<endl;
        cout<<"\t\t\t\t\t\t\t3.Close Application"<<endl<<endl;
        int ch;
        cout<<"\t\t\t\t\t\t\tEnter Option: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            system("cls");
            Student_pass();
            break;
        case 2:
            system("cls");
            main();
            break;
        case 3:
            exit(0);
        default:
            cout<<"\n\t\t\t\t\t           Invalid Choice!\n\n\t\t\t\           For Choice Again Enter 1 Or Enter 0 For Main Menu."<<endl;
            int c;
            cout<<"\n\t\t\t\t\t           Enter 1/0: ";
            cin>>c;
            switch(c)
            {
            case 1:
                system("cls");
                Stdnt_login();
                break;
            case 2:
                exit(0);
            }

        }
    }
}
//-----------------------------------------------------------------------------End Of Student Login Part--------------------------------------------------------------------------------------------








/*                                                             #################################
                                                                #          This Part For Student_Pass                        #
                                                                #################################
*/
void Student_pass()
{
    int choice;


    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t      ####################################################################"<<endl;
    cout<<endl;
    cout<<"\t\t\t                               For See  Updates\n\t\t\t\t\tYou Have To Registration and Login The System"<<endl;
    cout<<endl;
    cout<<"\t\t\t      ####################################################################"<<endl;
    cout<<endl<<endl;

    cout<<"\t\t\t\t\t\t\t1: REGISTRATION"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t2: LOGIN"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t3: Go to Main Menu"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t4: Close Applocation"<<endl<<endl;


    cout<<"\t\t\t  If You Have An Account Please Press 2 For Login or Press 1 for Registration"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\tEnter Options: ";

    cin>>choice;
    cout<<endl<<endl;

    switch(choice)
    {
    case 1:
        system("cls");
        Stdnt_reg();
        break;
    case 2:
        system("cls");
        Stdnt_login();
        break;
    case 3:
        system("cls");
        main();
        break;
    case 4:
        exit(0);
    default:
        cout<<"\n\t\t\t\t\t           Invalid Choice!\n\n\t\t\t\           For Choice Again Enter 1 Or Enter 0 For Main Menu."<<endl;
        int c;
        cout<<"\n\t\t\t\t\t           Enter 1/0: ";
        cin>>c;
        switch(c)
        {
        case 1:
            system("cls");
            Student_pass();
            break;
        case 2:
            break;
        }


    }


}
//-----------------------------------------------------------------------------End Of Student_Pass Part--------------------------------------------------------------------------------------------



int main()
{

    cout<<endl<<endl;
    cout<<"\t\t\t       ##############################################################"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t     Welcome To Our Result ManageMent System"<<endl;
    cout<<endl;
    cout<<"\t\t\t       ##############################################################"<<endl;
    cout<<endl<<endl;

    int choice;
    cout<<"\t\t\t\t\t           1.Student"<<endl<<endl;
    cout<<"\t\t\t\t\t           2.Admin"<<endl<<endl;
    cout<<"\t\t\t\t\t           3.Close Application"<<endl<<endl;
    cout<<"\t\t\t\t\t           Choice Your Option: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        system("cls");
        Student_pass();
        break;
   /* case 2:
        Admin_pass();
        break; */
    case 3:
        exit(0);

    default:
        cout<<"\n\t\t\t\t\t           Invalid Choice!\n\n\t\t\t\           For Choice Again Enter 1 Or Enter 0 For Exit."<<endl;
        int c;
        cout<<"\n\t\t\t\t\t           Enter 1/0: ";
        cin>>c;
        switch(c)
        {
        case 1:
            system("cls");
            main();
            break;
        case 2:
            break;
        }
    }

}
