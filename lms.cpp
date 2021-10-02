#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;

void AdminMenu();
void MainMenu();
void StudentMenu();

//declaration of class for books data
class Book{
    public:
    int bcode;
    string bname;
    string bauthor;
    void getBdata();
    void showBdata();
    string retbname(){
        return bname;
    }
};
//function to take input of book information
void Book::getBdata(){
    cout<<"\n\n"<<setw(58)<<"-----------------------------------";
    cout<<"\n"<<setw(55)<<" --> ENTER BOOK DATA BELOW <--";
    cout<<"\n"<<setw(58)<<"-----------------------------------";
    cout<<"\n\n"<<setw(43)<<"Enter Book Number: ";
    cin>>bcode;
    cin.ignore();
    cout<<"\n"<<setw(41)<<"Enter Book Name: ";
    getline(cin,bname);
    cout<<"\n"<<setw(45)<<"Enter Author's Name: ";
    getline(cin,bauthor);
    cout<<"\n"<<setw(58)<<"-----------------------------------";
}
//function to show the information of book
void Book::showBdata(){
    cout<<"\n"<<setw(28)<<bcode;
    cout<<setw(39)<<bname;
    cout<<setw(38)<<bauthor;
}


//declaration of class for student data 
class Student{
    public:
    int admino;
    string sname;
    int token;
    string issuedbook;
    void getSdata();
    void showSdata();
    void addtoken(){
        token = 1;
    }
    void resettoken(){
        token = 0;
    }
    void inibook(){
        issuedbook = '\0';
    }
    void getdataBI(int, string, string);
    void getdataBD(int, string);
};
//function to take input of student information
void Student::getSdata(){
    cout<<"\n\n"<<setw(58)<<"------------------------------------";
    cout<<"\n"<<setw(56)<<" --> ENTER STUDENT DATA BELOW <--";
    cout<<"\n"<<setw(58)<<"------------------------------------";
    cout<<"\n\n"<<setw(47)<<"Enter Admission Number: ";
    cin>>admino;
    cin.ignore();
    cout<<"\n"<<setw(35)<<"Enter Name: ";
    getline(cin,sname);
    cout<<"\n"<<setw(58)<<"------------------------------------";
}
//function to show student data
void Student::showSdata(){
    cout<<"\n"<<setw(26)<<admino;
    cout<<setw(39)<<sname;
    cout<<setw(31)<<issuedbook<<"["<<token<<"]";
}
void Student::getdataBI(int ad, string n, string b){
    admino = ad;
    sname = n;
    issuedbook = b;
    token = 1;
}
void Student::getdataBD(int adm, string nm){
    admino = adm;
    sname = nm;
    token = 0;
    issuedbook = '\0';
}


//function to add book in the database list
void addbook(){
    system("cls");
    Book obj;
    ofstream file;
    file.open("book.dat", ios::binary|ios::app|ios::out);
    obj.getBdata();
    file.write((char*)&obj, sizeof(obj));
    file.close();
    cout<<"\n"<<setw(48)<<"Book added succesfully! \n";
    cout<<"\n"<<setw(50)<<"Press 1 to add another book";
    cout<<"\n"<<setw(38)<<"[OR]";
    cout<<"\n"<<setw(76)<<"Press any number to return back to Administrator Menu";
    cout<<"\n"<<setw(27)<<"--> ";
    int reply;
    cin>>reply;
    if (reply == 1)
    {
        addbook();
    }
    else
    {
        AdminMenu();
    }
}


//function to show all the books stored in database for administrator menu
void showbooklist(){
    system("cls");
    Book obj;
    ifstream file;
    cout<<"\n"<<setw(77)<<"=============================";
    cout<<"\n"<<setw(71)<<"==> BOOK LIST <==";
    cout<<"\n"<<setw(77)<<"=============================";
    cout<<"\n"<<setw(108)<<"--------------------------------------------------------------------------------------------";
    cout<<"\n"<<setw(28)<<"BOOK CODE"<<setw(39)<<"BOOK NAME"<<setw(38)<<"AUTHOR NAME";
    cout<<"\n"<<setw(108)<<"--------------------------------------------------------------------------------------------";
    file.open("book.dat", ios::binary|ios::in);
    while (file.read((char*)&obj, sizeof(obj)))
    {
        obj.showBdata();
    }
    file.close();
    cout<<"\n"<<setw(108)<<"--------------------------------------------------------------------------------------------";
    cout<<"\n"<<setw(55)<<"Press any number for Administrator Menu";
    cout<<"\n"<<setw(25)<<"[OR]";
    cout<<"\n"<<setw(31)<<"Press 0 to Exit";
    cout<<"\n"<<setw(20)<<"--> ";
    int reply;
    cin>>reply;
    if (reply==0)
    {
        exit(0);
    }
    else{
        AdminMenu();
    }   
}

//function to show book list for student menu
void booklist(){
    system("cls");
    Book obj;
    ifstream file;
    cout<<"\n"<<setw(77)<<"=============================";
    cout<<"\n"<<setw(71)<<"==> BOOK LIST <==";
    cout<<"\n"<<setw(77)<<"=============================";
    cout<<"\n"<<setw(108)<<"--------------------------------------------------------------------------------------------";
    cout<<"\n"<<setw(28)<<"BOOK CODE"<<setw(39)<<"BOOK NAME"<<setw(38)<<"AUTHOR NAME";
    cout<<"\n"<<setw(108)<<"--------------------------------------------------------------------------------------------";
    file.open("book.dat", ios::binary|ios::in);
    while (file.read((char*)&obj, sizeof(obj)))
    {
        obj.showBdata();
    }
    file.close();
    cout<<"\n"<<setw(108)<<"--------------------------------------------------------------------------------------------";
    cout<<"\n"<<setw(49)<<"Press any number for Student Menu";
    cout<<"\n"<<setw(25)<<"[OR]";
    cout<<"\n"<<setw(31)<<"Press 0 to Exit";
    cout<<"\n"<<setw(20)<<"--> ";
    int reply;
    cin>>reply;
    if (reply==0)
    {
        exit(0);
    }
    else{
        StudentMenu();
    }   
}

//function to search any specific book in the list
void searchbook(){
    system("cls");
    Book obj;
    ifstream file;
    file.open("book.dat", ios::binary);
    cout<<"\n"<<setw(50)<<"Press 1 to search by Book Code";
    cout<<"\n"<<setw(37)<<"[OR]";
    cout<<"\n"<<setw(50)<<"Press 2 to search by Book Name";
    cout<<"\n\n"<<setw(24)<<"--> ";
    int reply;
    cin>>reply;

    if (reply==1)
    {
        system("cls");
        int code;
        cout<<"\n"<<setw(37)<<"Enter Book Code: ";
        cin>>code;
        int datafound=0;
        cout<<"\n"<<setw(108)<<"============================================================================================";
        cout<<"\n"<<setw(28)<<"BOOK CODE"<<setw(39)<<"BOOK NAME"<<setw(38)<<"AUTHOR NAME";
        cout<<"\n"<<setw(108)<<"============================================================================================";
        while (file.read((char*)&obj, sizeof(obj)))
        {
            if(obj.bcode == code){
                obj.showBdata();
                datafound = 1;
            }
        }
        if (datafound==0)
        {
            cout<<"\n"<<setw(42)<<"Book not found!!!";
        }
        cout<<"\n"<<setw(108)<<"--------------------------------------------------------------------------------------------";
        cout<<"\n"<<setw(55)<<"Press any number for Administrator Menu";
        cout<<"\n"<<setw(25)<<"[OR]";
        cout<<"\n"<<setw(31)<<"Press 0 to exit";
        cout<<"\n"<<setw(20)<<"--> ";
        int reply;
        cin>>reply;
        if (reply==0)
        {
            exit(0);
        }
        else{
            AdminMenu();
        }     
    }

    else if (reply==2)
    {
        system("cls");
        string boname;
        int datafound=0;
        cout<<"\n"<<setw(37)<<"Enter Book Name: ";
        cin.ignore();
        getline(cin,boname);
        cout<<"\n"<<setw(108)<<"============================================================================================";
        cout<<"\n"<<setw(28)<<"BOOK CODE"<<setw(39)<<"BOOK NAME"<<setw(38)<<"AUTHOR NAME";
        cout<<"\n"<<setw(108)<<"============================================================================================";
        while (file.read((char*)&obj, sizeof(obj)))
        {
            if(strcmp(obj.bname.c_str(), boname.c_str())==0)
            {
                obj.showBdata();
                datafound = 1;
            }
        }
        if (datafound==0)
        {
            cout<<"\n"<<setw(42)<<"Book not found!!!";
        }
        cout<<"\n"<<setw(108)<<"--------------------------------------------------------------------------------------------";
        cout<<"\n"<<setw(55)<<"Press any number for Administrator Menu";
        cout<<"\n"<<setw(25)<<"[OR]";
        cout<<"\n"<<setw(31)<<"Press 0 to exit";
        cout<<"\n"<<setw(20)<<"--> ";
        int reply;
        cin>>reply;
        if (reply==0)
        {
            exit(0);
        }
        else{
            AdminMenu();
        }     
    }

    else{
        cout<<"\n"<<setw(37)<<"Enter valid choice!";
        searchbook();
    }
    file.close();
}


//function to delete any specific book from list
void deletebook(){
    system("cls");
    string boname;
    cout<<"\n"<<setw(35)<<"Enter Book Name: ";
    cin.ignore();
    getline(cin, boname);
    Book obj;
    ifstream fin;
    ofstream fout;
    fin.open("book.dat", ios::binary | ios::in);
    fout.open("temp.dat", ios::binary | ios::out);
    while(fin.read((char*)&obj, sizeof(obj)))
    {
        if (strcmp(obj.bname.c_str(), boname.c_str()) != 0)
        {
            fout.write((char*)&obj, sizeof(obj));
        }
    }
    fin.close();
    fout.close();
    remove("book.dat");
    rename("temp.dat","book.dat");
    cout<<"\n\n"<<setw(51)<<"==> Book Deleted Successfully!!!\n";
    cout<<endl;
    cout<<"\n"<<setw(57)<<"Press any number for Administrator Menu";
    cout<<"\n"<<setw(27)<<"[OR]";
    cout<<"\n"<<setw(33)<<"Press 0 to Exit";
    cout<<"\n"<<setw(22)<<"--> ";
    int reply;
    cin>>reply;
    if (reply==0)
    {
        exit(0);
    }
    else{
        AdminMenu();
    }   
}


//function to create student account
void crstacc(){
    system("cls");
    Student obj;
    obj.getSdata();
    obj.resettoken();
    obj.inibook();
    ofstream file;
    file.open("student.dat", ios::binary | ios::app | ios::out);
    file.write((char*)&obj, sizeof(obj));
    file.close();
    cout<<"\n"<<setw(61)<<"Student account created succesfully! \n";
    cout<<"\n"<<setw(56)<<"Press 1 to create another account";
    cout<<"\n"<<setw(38)<<"[OR]";
    cout<<"\n"<<setw(76)<<"Press any number to return back to Administrator Menu";
    cout<<"\n"<<setw(27)<<"--> ";
    int reply;
    cin>>reply;
    if (reply == 1)
    {
        crstacc();
    }
    else
    {
        AdminMenu();
    }
}

//function to show the list of students registered in database
void showstulist(){
    system("cls");
    Student obj;
    ifstream file;
    file.open("student.dat", ios::binary | ios::in);
    cout<<"\n"<<setw(73)<<"============================";
    cout<<"\n"<<setw(69)<<"==> STUDENT LIST <==";
    cout<<"\n"<<setw(73)<<"============================";
    cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
    cout<<"\n"<<setw(31)<<"ADIMISSION NO."<<setw(34)<<"STUDENT NAME"<<setw(34)<<"BOOK ISSUED";
    cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
    while (file.read((char*)&obj, sizeof(obj)))
    {
        obj.showSdata();
    }
    file.close();
    cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
    cout<<"\n\n"<<setw(55)<<"Press any number for Administrator Menu";
    cout<<"\n"<<setw(25)<<"[OR]";
    cout<<"\n"<<setw(31)<<"Press 0 to exit";
    cout<<"\n"<<setw(20)<<"--> ";
    int reply;
    cin>>reply;
    if (reply==0)
    {
        exit(0);
    }
    else{
        AdminMenu();
    }     
}

//function to search student record
void searchstu(){
    system("cls");
    int adno;
    cout<<"\n"<<setw(46)<<"Enter Admission No.: ";
    cin>>adno;
    Student obj;
    ifstream file;
    file.open("student.dat", ios::binary);
    int found = 0;
    cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
    cout<<"\n"<<setw(31)<<"ADIMISSION NO."<<setw(34)<<"STUDENT NAME"<<setw(34)<<"BOOK ISSUED";
    cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
    while (file.read((char*)&obj, sizeof(obj)))
    {
        if (obj.admino == adno)
        {
            obj.showSdata();
            found = 1;
        }
    }
    if (found == 0)
    {
        cout<<"\n"<<setw(45)<<"Student not found!!!";
    }
    cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
    cout<<"\n"<<setw(55)<<"Press any number for Administrator Menu";
    cout<<"\n"<<setw(25)<<"[OR]";
    cout<<"\n"<<setw(31)<<"Press 0 to exit";
    cout<<"\n"<<setw(20)<<"--> ";
    int reply;
    cin>>reply;
    if (reply==0)
    {
        exit(0);
    }
    else{
        AdminMenu();
    }     
}

//function to modify student record
void modifystu(){
    system("cls");
    int adno, found = 0;
    Student obj;
    ifstream sfile("student.dat", ios::binary);
    ofstream tfile("temp.dat", ios::binary);
    sfile.seekg(0);
    cout<<"\n\n"<<setw(50)<<"Enter Admission Number: ";
    cin>>adno;
    while (sfile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.admino == adno){
            found = 1;
            cout<<"\n\n"<<setw(38)<<"CURRENT RECORD: ";
            cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
            cout<<"\n"<<setw(31)<<"ADIMISSION NO."<<setw(34)<<"STUDENT NAME"<<setw(34)<<"BOOK ISSUED";
            cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
            obj.showSdata();
            cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
            cout<<"\n\n"<<setw(38)<<"ENTER NEW DATA: ";
            obj.getSdata();
            obj.resettoken();
            obj.inibook();
            cout<<"\n\n"<<setw(52)<<"Record updated successfully!!!";
        }
        tfile.write((char*)&obj, sizeof(obj));
    }
    if (found == 0)
    {
        cout<<"\n"<<setw(61)<<"--> Student record doesn't exist!!!";
    }
    sfile.close();
    tfile.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
    cout<<"\n\n"<<setw(61)<<"Press any number for Administrator Menu";
    cout<<"\n"<<setw(31)<<"[OR]";
    cout<<"\n"<<setw(37)<<"Press 0 to exit";
    cout<<"\n"<<setw(26)<<"--> ";
    int reply;
    cin>>reply;
    if (reply==0)
    {
        exit(0);
    }
    else{
        AdminMenu();
    }       
}

//function to delete student record
void deletestu(){
    system("cls");
    int adno;
    cout<<"\n"<<setw(42)<<"Enter Admission Number: ";
    cin>>adno;
    Student obj;
    ifstream fin;
    ofstream fout;
    fin.open("student.dat", ios::binary | ios::in);
    fout.open("temp.dat", ios::binary | ios::out);
    while(fin.read((char*)&obj, sizeof(obj)))
    {
        if (obj.admino != adno)
        {
            fout.write((char*)&obj, sizeof(obj));
        }
    }
    fin.close();
    fout.close();
    remove("student.dat");
    rename("temp.dat","student.dat");
    cout<<"\n\n"<<setw(62)<<"==> Student Account Deleted Successfully!!!\n";
    cout<<endl;
    cout<<"\n"<<setw(57)<<"Press any number for Administrator Menu";
    cout<<"\n"<<setw(27)<<"[OR]";
    cout<<"\n"<<setw(33)<<"Press 0 to Exit";
    cout<<"\n"<<setw(22)<<"--> ";
    int reply;
    cin>>reply;
    if (reply==0)
    {
        exit(0);
    }
    else{
        AdminMenu();
    }   

}

//function to issue book
void bookissue(){
    system("cls");
    int bfound = 0;
    int sfound = 0;
    Student obj1;
    Book obj2;
    fstream bfile;
    bfile.open("book.dat", ios::binary|ios::in|ios::out);
    ofstream tfile;
    tfile.open("temp.dat", ios::binary);
    fstream sfile;
    sfile.open("student.dat", ios::binary|ios::in|ios::out);
    sfile.seekg(0);
    bfile.seekg(0);
    string book;
    int adno;
    cout<<"\n"<<setw(77)<<"============================";
    cout<<"\n"<<setw(72)<<"==> BOOK ISSUE <==";
    cout<<"\n"<<setw(77)<<"============================";
    cout<<"\n\n"<<setw(71)<<"Enter your Admission Number: ";
    cin>>adno;
    while (sfile.read((char*)&obj1, sizeof(obj1)))
    {
        if(obj1.admino == adno){
            sfound = 1;
            if (obj1.token == 0)
            {
                cout<<"\n"<<setw(63)<<"Enter the Book name: ";
                cin.ignore();
                getline(cin, book);
                while (bfile.read((char*)&obj2, sizeof(obj2)))
                {
                    if(strcmp(obj2.bname.c_str(), book.c_str()) == 0){
                        bfound = 1;
                        cout<<"\n"<<setw(108)<<"============================================================================================";
                        cout<<"\n"<<setw(28)<<"BOOK CODE"<<setw(39)<<"BOOK NAME"<<setw(38)<<"AUTHOR NAME";
                        cout<<"\n"<<setw(108)<<"============================================================================================";
                        obj2.showBdata();
                        cout<<"\n"<<setw(108)<<"--------------------------------------------------------------------------------------------";
                        obj1.getdataBI(obj1.admino, obj1.sname, book);
                        cout<<"\n\n"<<setw(70)<<"Book Issued Successfully!!!";
                    }   
                }
                if (bfound == 0)
                {
                    cout<<"\n"<<setw(71)<<"--> This Book is Unavailable!";
                }
            }
            else{
                cout<<"\n"<<setw(87)<<"--> You have not deposited the previous book.";
            }
        }
        tfile.write((char*)&obj1, sizeof(obj1)); 
    }
    if(sfound == 0){
        cout<<"\n"<<setw(78)<<"--> Student record does not exist!!!";
    }
    sfile.close();
    tfile.close();
    bfile.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
    cout<<"\n\n"<<setw(85)<<"Press any number to go back in Student Menu";
    cout<<"\n"<<setw(51)<<"[OR]";
    cout<<"\n"<<setw(57)<<"Press 0 to Exit";
    cout<<"\n"<<setw(46)<<"--> ";
    int reply;
    cin>>reply;
    if (reply==0)
    {
        exit(0);
    }
    else{
        StudentMenu();
    }   
}

//function to deposite book
void bookdeposite(){
    system("cls");
    int adno;
    int ch, opt;
    cout<<"\n"<<setw(77)<<"============================";
    cout<<"\n"<<setw(73)<<"==> BOOK DEPOSIT <==";
    cout<<"\n"<<setw(77)<<"============================";
    cout<<"\n\n"<<setw(71)<<"Enter your Admission Number: ";
    cin>>adno;
    Student obj;
    fstream sfile;
    ofstream tfile;
    sfile.open("student.dat", ios::binary|ios::in|ios::out);
    tfile.open("temp.dat", ios::binary);
    while (sfile.read((char*)&obj, sizeof(obj)))
    {
        if(obj.admino == adno)
        {
            cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
            cout<<"\n"<<setw(31)<<"ADIMISSION NO."<<setw(34)<<"STUDENT NAME"<<setw(34)<<"BOOK ISSUED";
            cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
            obj.showSdata();
            cout<<"\n"<<setw(100)<<"------------------------------------------------------------------------------------";
            if (obj.token == 1)
            {
                obj.getdataBD(obj.admino, obj.sname);
                cout<<"\n\n"<<setw(73)<<"Book Deposited Successfully!!!";
            }
            else{
                cout<<"\n"<<setw(72)<<"You haven't issued any book!!!";
            }
        }
        tfile.write((char*)&obj, sizeof(obj)); 
    }
    sfile.close();
    tfile.close();
    remove("student.dat");
    rename("temp.dat", "student.dat");
    cout<<"\n\n"<<setw(85)<<"Press any number to go back in Student Menu";
    cout<<"\n"<<setw(51)<<"[OR]";
    cout<<"\n"<<setw(57)<<"Press 0 to Exit";
    cout<<"\n"<<setw(46)<<"--> ";
    int reply;
    cin>>reply;
    if (reply==0)
    {
        exit(0);
    }
    else{
        StudentMenu();
    }    
}

//function for Student Menu 
void StudentMenu(){
    system("cls");
    int opt;
    cout<<"\n"<<setw(50)<<"===============================";
    cout<<"\n"<<setw(41)<<"STUDENT MENU";
    cout<<"\n"<<setw(50)<<"===============================";
    cout<<"\n\n"<<setw(33)<<"[1] Book Issue";
    cout<<"\n"<<setw(35)<<"[2] Book Deposit";
    cout<<"\n"<<setw(32)<<"[3] Book List";
    cout<<"\n"<<setw(32)<<"[4] Main Menu";
    cout<<"\n"<<setw(27)<<"[5] Exit";
    cout<<"\n\n"<<setw(50)<<"-------------------------------";
    cout<<"\n"<<setw(53)<<"Please choose option [1/2/3/4/5]: ";
    cin>>opt;
    switch (opt)
    {
    case 1:
        bookissue();
        break;
    case 2:
        bookdeposite();
        break;
    case 3:
        booklist();
        break;
    case 4:
        MainMenu();
        break;
    case 5:
        exit(0);
        break;

    default:
        cout<<"\n\n --> Enter valid option!";
        StudentMenu();
        break;
    }
}


//function for Administrator Menu
void AdminMenu(){
    system("cls");
    int opt;
    cout<<"\n"<<setw(63)<<"============================================";
    cout<<"\n"<<setw(50)<<"ADMINISTRATOR MENU";
    cout<<"\n"<<setw(63)<<"============================================";
    cout<<"\n\n"<<setw(46)<<"[1]  Create Student Account";
    cout<<"\n"<<setw(51)<<"[2]  Display all Student Records";
    cout<<"\n"<<setw(45)<<"[3]  Search Student Record";
    cout<<"\n"<<setw(45)<<"[4]  Modify Student Record";
    cout<<"\n"<<setw(45)<<"[5]  Delete Student Record";
    cout<<"\n"<<setw(32)<<"[6]  Add Book";
    cout<<"\n"<<setw(41)<<"[7]  Display all Books";
    cout<<"\n"<<setw(35)<<"[8]  Search Book";
    cout<<"\n"<<setw(35)<<"[9]  Delete Book";
    cout<<"\n"<<setw(33)<<"[10] Main Menu";
    cout<<"\n"<<setw(28)<<"[11] Exit";
    cout<<"\n\n"<<setw(63)<<"--------------------------------------------";
    cout<<"\n"<<setw(45)<<"Please enter your choice: ";
    cin>>opt;
    if (opt==1)
    {
        crstacc();
    }
    else if (opt==2)
    {
        showstulist();
    }
    else if (opt==3)
    {
        searchstu();
    }
    else if (opt==4)
    {
        modifystu();
    }
    else if (opt==5)
    {
        deletestu();
    }
    
    else if (opt==6)
    {
        addbook();
    }
    else if (opt==7)
    {
        showbooklist();
    }   
    else if (opt==8)
    {
        searchbook();
    }
    else if (opt==9)
    {
        deletebook();
    }
    
    else if (opt==10)
    {
        MainMenu();
    }
    else if (opt==11)
    {
        exit(0);
    }
    else{
        cout<<"\n"<<setw(37)<<"Enter valid choice!";
        AdminMenu();
    }
}


//function for Main Menu
void MainMenu(){
    system("cls");
    int opt;
    cout<<"\n"<<setw(50)<<"===============================";
    cout<<"\n"<<setw(40)<<"Main Menu";
    cout<<"\n"<<setw(50)<<"===============================";
    cout<<"\n\n"<<setw(35)<<"[1] Student Menu";
    cout<<"\n"<<setw(41)<<"[2] Administrator Menu";
    cout<<"\n"<<setw(27)<<"[3] Exit";
    cout<<"\n\n"<<setw(50)<<"-------------------------------";
    cout<<"\n"<<setw(49)<<"Please choose option [1/2/3]: ";
    cin>>opt;
    if (opt==1)
    {
        StudentMenu();
    }
    else if (opt==2)
    {
        system("cls");
        int pass;
        cout<<"\n\n"<<setw(40)<<"Enter password: ";
        cin>>pass;
        if (pass == 123456)
        {
            AdminMenu();
        }
        else{
            cout<<"\n --> Wrong password try again!";
            MainMenu();
        }
    }
    else if (opt==3)
    {
        exit(0);
    }
    else
    {
        cout<<"\n"<<setw(45)<<" --> Enter valid option!";
        MainMenu();
    }   
}

//welcome page
void start(){
    system("cls");
    cout<<"\n\n\n\n\n\n"<<setw(80)<<"# # # # # # # # # # # # # # # #";
    cout<<"\n"<< setw(80) <<"#                             #";
    cout<<"\n"<< setw(80) <<"#           LIBRARY           #";
    cout<<"\n"<< setw(80) <<"#          MANAGEMENT         #";
    cout<<"\n"<< setw(80) <<"#            SYSTEM           #";
    cout<<"\n"<< setw(80) <<"#                             #";
    cout<<"\n"<< setw(80) <<"# # # # # # # # # # # # # # # #";
    cout<<"\n\n\n\n\n\n";
    cout<<"\n"<<setw(38)<<"CREATED BY: ";
    cout<<"\n"<<setw(103)<<"-----------------------------------------------------------------------------";
    cout<<"\n"<<setw(37)<<"Abhay Ojha"<<setw(33)<<"Suryali Suman"<<setw(32)<<"Nilesh Pandey";
    cout<<"\n"<<setw(36)<<"20BCS3857"<<setw(30)<<"20BCS3866"<<setw(32)<<"20BCS3860";
    cout<<"\n"<<setw(103)<<"-----------------------------------------------------------------------------";
    int opt;
    cout<<"\n\n"<<setw(47)<<"Press 1 for Main Menu";
    cout<<"\n"<<setw(35)<<"[OR]";
    cout<<"\n"<<setw(41)<<"Press 0 to Exit";
    cout<<"\n"<<setw(30)<<"--> ";
    cin>>opt;
    if (opt == 1)
    {
        MainMenu();
    }
    else if (opt == 0)
    {
        exit(0);
    }
    else{
        cout<<"\n"<<setw(48)<<"Enter valid choice!!!";
        start();
    }
    cout<<endl;
}

//main function(driver)
int main(){  
    start();
    return 0;
}
