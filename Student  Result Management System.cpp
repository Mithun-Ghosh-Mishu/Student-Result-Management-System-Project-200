#include<bits/stdc++.h>
using namespace std;
void  Student_pass();
void Stdnt_login();
void Student_Panel();
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
        Student_Panel();
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


void Student_Panel()
{
      cout<<endl<<endl<<endl;

    cout<<"\t\t\t       ##############################################################"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t         Welcome To Student Panel"<<endl;
    cout<<endl;
    cout<<"\t\t\t       ##############################################################"<<endl;
    cout<<endl<<endl;

    cout<<"\t\t\t\t\t          1. See Overall Your Result."<<endl<<endl;
    cout<<"\t\t\t\t\t          2. Go to Previous Menu."<<endl<<endl;
    cout<<"\t\t\t\t\t          3. Go to  Main Menu."<<endl<<endl;
    cout<<"\t\t\t\t\t          4. Close Application!"<<endl<<endl;
    int Ch;
    cout<<"\t\t\t\t\t          Choice Your Option:  ";
    cin>>Ch;
    switch(Ch)
    {
    case 1:
        system("cls");
//        Overall_Result();
        break;
    case 2:
        system("cls");
        Student_pass();
        break;
    case 3:
        system("cls");
        main();
        break;
    case 4:
        break;
    default:
        cout<<"\n\t\t\t\t\t           Invalid Choice!\n\n\t\t\t\           For Choice Again Enter 1 Or Enter 0 For Main Menu."<<endl;
        int c;
        cout<<"\n\t\t\t\t\t           Enter 1/0: ";
        cin>>c;
        switch(c)
        {
        case 1:
            system("cls");
            Student_Panel();
            break;
        case 2:
            break;
        }
    }

}

// --------------------End Of Student Panel-----------------------------------------



/*                                                                     #################################
                                                                        #              Result Adding Part For Admin        #
                                                                       #################################  */

void Add_Result()
{
    cout<<endl<<endl;
    cout<<"                                         ################################## "<<endl;
    cout<<"                                         #                                #"<<endl;
    cout<<"                                         #      Fill This Information     #"<<endl;
    cout<<"                                         #                                #"<<endl;
    cout<<"                                         ##################################"<<endl<<endl<<endl;

    string i,id,id2,nm;

    cout<<"\n\t\t\t\t\t  Entered Id Format Is : ###-###-###"<<endl<<endl;
    cout<<"\t\t\t\t\t    Enter Student id: ";
    cin>>i;

    string file =  i + ".csv";
    ifstream read;
    read.open(file.c_str());
    getline(read,nm,',');
    getline(read,id,'\n');
    //read.close();
    if(i==nm||i==id)
    {
        cout<<"\n\t\t\t\t\t     Result File Already Exits!"<<endl;
        cout<<"\n\t\t\t\t\t\tFor Add New Result\n\t\t\t\t\t    Please Go To Previous Menu"<<endl;
        int c;
        cout<<"\n\t\t\t\t\t          1.Previous Menu"<<endl;
        cout<<"\t\t\t\t\t          2.Main Menu"<<endl;
        cout<<"\n\t\t\t\t\t         Enter Choice: ";
        cin>>c;
        if(c==1)
        {
            system("cls");
            Add_Result();

        }
        else
        {
            system("cls");
            main();
        }
    }
    else
    {
        int n; //n means numbers of subjects.
        char na[100],Batch[100],Dept[100],Sec[100];
        string ID;
        char name[100],res[100]; // for add sub name and result.

        string id="Id",nam="Name",Dep="Department",Bat="Batch",Sect="Sec";
        ofstream file;
        string fileName = i+".csv";
        file.open(fileName.c_str(),ios::app);


        file<<id<<","<<i<<endl;
        cout<<"\n\t\t\t\t\t         Enter Name : ";
        scanf(" %[^\n]s",na);
        cout<<endl;
        file<<nam<<","<<na<<endl;
        cout<<"\t\t\t\t\t         Enter Dept. : ";
        scanf(" %[^\n]s",Dept);
        cout<<endl;
        file<<Dep<<","<<Dept<<endl;
        cout<<"\t\t\t\t\t         Enter Batch : ";
        scanf(" %[^\n]s",Batch);
        cout<<endl;
        file<<Bat<<","<<Batch<<endl;
        cout<<"\t\t\t\t\t         Enter Sec : ";
        scanf(" %[^\n]s",Sec);
        cout<<endl;
        file<<Sect<<","<<Sec<<endl;

        cout<<"\n\n\t\t\t\t\tEnter Number of Subject For Add: ";
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cout<<"\n\n\t\t\t\t\t\tEnter Subject "<<i<<":";
            scanf(" %[^\n]s",name);

            cout<<endl;
            cout<<"\t\t\t\t\t\tEnter Result  "<<i<<":";
            scanf(" %[^\n]s",res);
            cout<<endl;

            file<<name<<","<<res<<endl;
        }

    }

}
//------------------------------------------------------------------------End Of Result Adding Part------------------------------------------------------------------------------------------------





/*                                                                     #################################
                                                                        #                        Admin_Login  Part                         #
                                                                       #################################  */
void Admin_Login()
{
    cout<<"\t\t\t       ##############################################################"<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t           Welcome To Admin Panel"<<endl;
    cout<<endl;
    cout<<"\t\t\t       ##############################################################"<<endl;
    cout<<endl<<endl;

    int ch;

    cout<<"\t\t\t\t\t           1. Add  Result For New Student"<<endl<<endl;
    cout<<"\t\t\t\t\t           2. Modify Previous Result"<<endl<<endl;
    cout<<"\t\t\t\t\t           3. Delete Any Record"<<endl<<endl;
    cout<<"\t\t\t\t\t           4. Change Admin Password"<<endl<<endl;
    cout<<"\t\t\t\t\t           5. Go To Main Menu"<<endl<<endl;
    cout<<"\t\t\t\t\t           6. Close Application!"<<endl<<endl;
    cout<<"\t\t\t\t\t           Choice Option: ";

    cin>>ch;
    switch(ch)
    {
    case 1:
        system("cls");
        Add_Result();
        break;
    case 2:
        system("cls");
//        Modify_Result();
        break;
    case 3:
        system("cls");
//        Delete_Any_Record();
        break;
    case 4:
        system("cls");
//        Change_Admin_Pass();
        break;
    case 5:
        system("cls");
        main();
        break;
    case 6:
        break;
    default:
        cout<<"\n\t\t\t\t\t           Invalid Choice!\n\n\t\t\t\           For Choice Again Enter 1 Or Enter 0 For Main Menu."<<endl;
        int c;
        cout<<"\n\t\t\t\t\t           Enter 1/0: ";
        cin>>c;
        switch(c)
        {
        case 1:
            system("cls");
            Admin_Login();
            break;
        case 2:
            break;
        }
    }
}
//----------------------------------------------------------------------End Of Admin_Login--------------------------------------------------------------------------------------------------



/*                                                                     #################################
                                                                        #                        Admin_Pass  Part                            #
                                                                       #################################  */
void Admin_pass()
{
    string c,ch;
    cout<<"\n\t\t\t\t\t           Enter Pass: ";
    cin>>c;
    ifstream pass;
    pass.open("Admin_pass.txt");
    getline(pass,ch);
    if(ch==c)
    {
        system("cls");
        Admin_Login();
    }
    else
    {

        cout<<"\t\t\t\t\tInvalid Password! Please try agin!!!"<<endl<<endl;
        Admin_pass();

    }
}
//-----------------------------------------------------------------------------Admin_PassWord--------------------------------------------------------------------------------------------------




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
    case 2:
        Admin_pass();
        break;
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
