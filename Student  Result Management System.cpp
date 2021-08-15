#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
void  Student_pass();
void Stdnt_login();
void  Student_Panel();
void Admin_Login();
int main();
/*                                                             #################################
                                                                #          This Part For Login Boolean Function     #
                                                                #################################
*/
bool IsLoggedIn()
{
    const int maxpasslength = 8;
    string username, usrnm,password, pss;
    char ch, pass[maxpasslength];
    int charposition = 0;



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

    //Start password handling part
    while(1)
    {

        ch = getch();
        if(ch==13)  //if user Hits ENTER BUTTON
        {

            break;

        }
        else if(ch==0)   //if user enter backspace
        {

            if(charposition > 0)
            {
                charposition--;
                pass[charposition] = '\0';
                printf("\b \b");
            }

        }
        else if(ch == 31 || ch == 9)    //if user enter Space / Tab
        {

            continue;
        }
        else
        {

            if(charposition<maxpasslength)
            {
                pass[charposition] = ch;
                charposition++;
                cout<<"*";
            }
            else
            {
                cout<<"Your Password Length Exceeds Maximum Password Length"<<endl;
                break;
            }
        }

    }
    pass[charposition] = '\0';
    password = pass;

    //End of password handling part

    ifstream readFile;
    string file =  username + ".txt";
    readFile.open(file.c_str());
    getline(readFile, usrnm);
    getline(readFile,pss);
    readFile.close();

    if(usrnm == username && password == pss)
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
    const int maxpasslength = 8;
    char ch, pass[maxpasslength];
    int charposition = 0;


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

    //Start password handling part
    while(1)
    {

        ch = getch();
        if(ch==13)  //if user Hits ENTER BUTTON
        {

            break;

        }
        else if(ch==0)   //if user enter backspace
        {

            if(charposition > 0)
            {
                charposition--;
                pass[charposition] = '\0';
                printf("\b \b");
            }

        }
        else if(ch == 31 || ch == 9)    //if user enter Space / Tab
        {

            continue;
        }
        else
        {

            if(charposition<=maxpasslength)
            {
                pass[charposition] = ch;
                charposition++;
                cout<<"*";
            }
            else
            {
                cout<<"Your Password Length Exceeds Maximum Password Length"<<endl;
                break;
            }
        }

    }
    pass[charposition] = '\0';
    password = pass;

    //End of password handling part

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
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t\t    Registration successful"<<endl<<endl;

}
//-----------------------------------------------------------------    ----End Of Student Registration Part--------------------------------------------------------------------------------------------



/*                                                             #################################
                                                               # This Part For Student_Login   #
                                                               #################################
*/
void Stdnt_login()
{

    bool status = IsLoggedIn();

    if(status)
    {
        cout<<"\t\t\t\t\t\t   Successfully Logged In"<<endl;

        system("cls");
        Student_Panel();
    }
    else
    {
        cout<<endl<<endl;
        cout<<"\t\t\t\t\t\t\tInvalid Username  Or Password"<<endl<<endl;
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
            IsLoggedIn();
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




/*                                                             #################################
                                                                #          This Part For Student Result Saw        #
                                                                #################################
*/

int Overall_Result()
{
    cout<<endl<<endl<<endl;

    cout<<"                                                ################################## "<<endl;
    cout<<"                                                #                                #"<<endl;
    cout<<"                                                #     Fill Up This Information    #"<<endl;
    cout<<"                                                #                                #"<<endl;
    cout<<"                                                ##################################"<<endl<<endl<<endl;


    string i,id,nm,user,usrn;
    cout<<"\n\t\t\t\t\t\tEntered Id Format Is : ###-###-###"<<endl<<endl;
    cout<<"\n\t\t\t\t\t\t   Enter Your Id :  ";
    cin>>i;
    string file =  i + ".csv";
    ifstream read;
    read.open(file.c_str());
    getline(read,nm,',');
    getline(read,id,'\n');

    if(i==nm||i==id)
    {
        system("cls");
        cout<<endl<<endl<<endl;
        cout<<"                                            ################################## "<<endl;
        cout<<"                                            #                                #"<<endl;
        cout<<"                                            #  Here Is Your Overall Result   #"<<endl;
        cout<<"                                            #                                #"<<endl;
        cout<<"                                            ##################################"<<endl<<endl<<endl;

        string subject,result;
        ifstream readResult;
        readResult.open(file.c_str());

        while(readResult.good())
        {
            getline(readResult,subject,',') ;
            getline(readResult,result,'\n') ;

            cout<<"\n\t\t\t\t\t    "<<subject<<" -- "<<result;
            cout<<endl;

        }
        readResult.close();

        int c;

        cout<<endl<<endl;
        cout<<"\n\t\t\t\t\tEnter 1 For Main Menu 0 for Exit: ";
        cin>>c;
        if(c==1)
        {
            system("cls");
            main();

        }
        else
        {
            exit(0);
        }

    }
    else
    {
        int ch;
        cout<<"\n\t\t\t\t\t               Invalid Id Format! Please Try Again"<<endl<<endl;
        cout<<"\t\t\t\t\t         Enter 1 for Try Again, 2 for Main Menu Or 0 for Exit!"<<endl<<endl;

        cout<<"\t\t\t\t\t                           Enter Choice:";
        cin>>ch;

        switch(ch)
        {

        case 1:
            system("cls");
            Overall_Result();
            break;
        case 2:
            system("cls");
            Student_Panel();
        case 3:
            break;
        }
    }


} //                                                              --------------------End Of ResultShowing Part---------------------






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
        Overall_Result();
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
        cout<<"\n\t\t\t\t\t          1.Try With New ID"<<endl;
        cout<<"\t\t\t\t\t           2.Main Menu"<<endl;
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


        file.close();

        int c;

        cout<<"\n\t\t\t\t\t     Result Adding Successful "<<endl;
        cout<<"\t\t\t\t\t       Enter  1 for Main Menu or 0 for Exit"<<endl;
        cout<<"\n\t\t\t\t\t     Enter Choice: ";
        cin>>c;
        if(c==1)
        {
            system("cls");
            main();

        }
        else
        {
            exit(0);
        }


    }

}
//------------------------------------------------------------------------End Of Result Adding Part------------------------------------------------------------------------------------------------





/*                                                                     #################################
                                                                       #    Modify_Result    Part      #
                                                                       #################################  */
//Add new result On Previous Result Sheet

void Modify_Result()
{
    cout<<endl<<endl<<endl;
    cout<<"                                      ################################## "<<endl;
    cout<<"                                      #                                #"<<endl;
    cout<<"                                      #  Fill This Information         #"<<endl;
    cout<<"                                      #                                #"<<endl;
    cout<<"                                      ##################################"<<endl<<endl<<endl;


    string i,id,id2,nm;

    cout<<"\n\t\t\t\t      Entered Id Format Is : ###-###-###"<<endl<<endl;
    cout<<"\t\t\t\t\t Enter Student Id: ";
    cin>>i;

    string file =  i + ".csv";
    ifstream read;
    read.open(file.c_str());
    getline(read,nm,',');
    getline(read,id,'\n');

    if(i==nm||i==id)
    {
        int n;
        char name[100],res[100];

        cout<<"\n\n\t\t\t\t\tEnter Number of Subject For Add: ";
        cin>>n;

        ofstream file;
        string fileName = id+".csv";

        file.open(fileName.c_str(),ios::app);

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
        file.close();

        int c;

        cout<<"\n\t\t\t\t\t     Result Adding Successful "<<endl;
        cout<<"\t\t\t\t\t       Enter  1 for Main Menu or 0 for Exit"<<endl;
        cout<<"\n\t\t\t\t\t     Enter Choice: ";
        cin>>c;
        if(c==1)
        {
            system("cls");
            main();

        }
        else
        {
            exit(0);
        }
    }
    else
    {
        int ch;
        cout<<"\n\n\t\t\t\t\t\tFile Not Exits"<<endl<<endl;
        cout<<"\n\t\t\t\tEnter 1 For Search Id Again Or 0 For Main Menu"<<endl<<endl;
        cout<<"\t\t\t\t\t\tEnter 0/1 : ";
        cin>>ch;
        if(ch==1)
        {
            system("cls");
            Modify_Result();
        }
        else
            main();
    }

}
//                                                                       --------------------End Of Result Modifying Part-----------------------------------------------------------------------------------------


/*                                                                     #################################
                                                                       # Delete_record   Part          #
                                                                       #################################  */

void Delete_Any_Record()
{

    cout<<endl<<endl<<endl;
    cout<<"                                      #######################################################################"<<endl;
    cout<<"                                      #                                                                     #"<<endl;
    cout<<"                                      #  For Delete Record Please Follow The Instruction                    #"<<endl;
    cout<<"                                      #                                                                     #"<<endl;
    cout<<"                                      #  If Delete Any Student Result  Please Enter Student Id Number(.csv) #"<<endl;
    cout<<"                                      #                                                                     #"<<endl;
    cout<<"                                      #  Or Delete UserName From DataBase Enter Username(.txt)              #"<<endl;
    cout<<"                                      #                                                                     #"<<endl;
    cout<<"                                      #######################################################################"<<endl<<endl<<endl;

    int ss;
    char file[100];
    cout<<"\n\t\t\t\t         Enter File Name You Want To Delete  :  ";
    scanf(" %[^\n]s",file);


    ss=remove(file);

    if(ss==0)
    {
        int c;
        cout<<"\n\n\t\t\t\t                    File Deleted Successfuly."<<endl;
        cout<<"\n\n\t\t\t\t            Enter 1 For Admin Panel Or 0 for Main Menu"<<endl<<endl;
        cout<<"\t\t\t\t                         Enter 0/1 : ";
        cin>>c;
        if(c==1)
        {
            system("cls");
            Admin_Login();
        }
        else
        {
            system("cls");
            main();
        }
    }
    else
    {
        cout<<"\n\n\t\t\t\t                        File Not Found!"<<endl;
        int c;
        cout<<"\n\t\t\t\t           Enter 1 For Try Again Or 0 for Admin Panel"<<endl<<endl;
        cout<<"\t\t\t\t                        Enter 0/1 : ";
        cin>>c;
        if(c==1)
        {
            system("cls");
            Delete_Any_Record();
        }
        else
        {
            system("cls");
            Admin_Login();
        }
    }

}

//----------------------------------------------------------------------------End Of Change_Delete Part------------------------------------------------------------------------------------------------------------




/*                                                                     #################################
                                                                       #        Admin_Pass_cng   Part  #
                                                                       #################################  */

void Change_Admin_Pass()
{
    cout<<endl<<endl<<endl;
    cout<<"                                      #######################################################"<<endl;
    cout<<"                                      #                                                     #"<<endl;
    cout<<"                                      #  For Change Password Please Follow The Instruction  #"<<endl;
    cout<<"                                      #                                                     #"<<endl;
    cout<<"                                      #######################################################"<<endl<<endl<<endl;

    const int maxpasslength = 8;
    char ch, pass[maxpasslength];
    int charposition = 0;
    string old_pass;

    cout<<"\n\t\t\t\t                 Enter Your Old Password: ";

    //Start Password Handling Part

    while(1)
    {

        ch = getch();
        if(ch==13)  //if user Hits ENTER BUTTON
        {

            break;

        }
        else if(ch==0)   //if user enter backspace
        {

            if(charposition > 0)
            {
                charposition--;
                pass[charposition] = '\0';
                printf("\b \b");
            }

        }
        else if(ch == 31 || ch == 9)    //if user enter Space / Tab
        {

            continue;
        }
        else
        {

            if(charposition<maxpasslength)
            {
                pass[charposition] = ch;
                charposition++;
                cout<<"*";
            }
            else
            {
                cout<<"Your Password Length Exceeds Maximum Password Length"<<endl;
                break;
            }
        }

    }
    pass[charposition] = '\0';
    old_pass = pass;

    ifstream pas;
    pas.open("Admin_Pass.txt");
    string psrd;
    getline(pas,psrd);
    pas.close();

    if(old_pass==psrd)
    {

        string cc;
        ofstream ps;

        const int maxpasslength = 8;
        char ch, pass[maxpasslength];
        int charposition = 0;

        ps.open("Admin_Pass.txt",ios::trunc);

        cout<<"\n\n\t\t\t\t                 Enter New Pass: ";

        //Start Password Handling Part

        while(1)
        {

            ch = getch();
            if(ch==13)  //if user Hits ENTER BUTTON
            {

                break;

            }
            else if(ch==0)   //if user enter backspace
            {

                if(charposition > 0)
                {
                    charposition--;
                    pass[charposition] = '\0';
                    printf("\b \b");
                }

            }
            else if(ch == 31 || ch == 9)    //if user enter Space / Tab
            {

                continue;
            }
            else
            {

                if(charposition<maxpasslength)
                {
                    pass[charposition] = ch;
                    charposition++;
                    cout<<"*";
                }
                else
                {
                    cout<<"Your Password Length Exceeds Maximum Password Length"<<endl;
                    break;
                }
            }

        }
        pass[charposition] = '\0';
        cc = pass;
        ps<<cc;
        ps.close();
        //End of Password Handling Part




        cout<<endl<<endl;
        cout<<"\n\t\t\t\t              Successfully Password Change"<<endl;
        int c;
        cout<<"\n\t\t\t\t            Enter 1 for main menu or 0 for exit: ";
        cin>>c;
        if(c=1)
        {
            system("cls");
            main();

        }
        else
        {
            exit(0);
        }

    }
    else
    {

        cout<<"\n\t\t\t\t                       Invalid Password!"<<endl;
        cout<<"\n\t\t\t\t              Enter 1 For Retry Or 0 For Main Menu"<<endl;
        int c;
        cout<<"\n\t\t\t\t                       Enter 0/1 : ";
        cin>>c;
        if(c=1)
        {
            system("cls");
            Change_Admin_Pass();

        }
        else
        {
            system("cls");
            Admin_Login();
        }

    }

}
//--------------------------------------------------------------------------End Of Change_Admin_Pass Part------------------------------------------------------------------------------------------------------------





/*                                                                     #################################
                                                                       # Admin_Login  Part             #
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
    cout<<"\t\t\t\t\t           2. Add New Result in Previous Result"<<endl<<endl;
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
        Modify_Result();
        break;
    case 3:
        system("cls");
        Delete_Any_Record();
        break;
    case 4:
        system("cls");
        Change_Admin_Pass();
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
                                                                       #        Admin_Pass  Part       #
                                                                       #################################  */
void Admin_pass()
{
    string password,pss;
    const int maxpasslength = 8;
    char ch, pass[maxpasslength];
    int charposition = 0;

    cout<<"\n\t\t\t\t\t           Enter Pass: ";

    //Start password handling part

    while(1)
    {

        ch = getch();
        if(ch==13)  //if user Hits ENTER BUTTON
        {

            break;

        }
        else if(ch==0)   //if user enter backspace
        {

            if(charposition > 0)
            {
                charposition--;
                pass[charposition] = '\0';
                printf("\b \b");
            }

        }
        else if(ch == 31 || ch == 9)    //if user enter Space / Tab
        {

            continue;
        }
        else
        {

            if(charposition<maxpasslength)
            {
                pass[charposition] = ch;
                charposition++;
                cout<<"*";
            }
            else
            {
                cout<<"Your Password Length Exceeds Maximum Password Length"<<endl;
                break;
            }
        }

    }
    pass[charposition] = '\0';
    password = pass;

    //end of password handling part

    ifstream pas;
    pas.open("Admin_pass.txt");
    getline(pas,pss);
    if(pss==password)
    {
        system("cls");
        Admin_Login();
    }
    else
    {

        cout<<endl;
        cout<<"\t\t\t\t\tInvalid Password! Please try again!!!"<<endl<<endl;
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
