#include<iostream>
#include<fstream> //FOR FILE HANDLING
#include<windows.h> // FOR COLOURING
using namespace std;
const int max_students=500;  //MAX STUDENTS CAN BE ADJUSTED ACCORDING TO ADMIN OR COLLEGE REQUIREMENT AND OTHER DATA TYPES(USED FOR ARRAY SIZE)
const int max_teachers=500;  //MAX TEACHERS CAN BE ADJUSTED ACCORDING TO ADMIN OR COLLEGE REQUIREMENT AND OTHER DATA TYPES
int color;
bool loginadmin(string user,string pass);  
int addstudent(string student[][5],int studentcount);  
int updatestudent(string student[][5],int studentcount);
int deletestudent(string student[][5],int studentcount);
int viewstudent(string student[][5],int studentcount);
int addteacher(string teacher[][4],int teachercount);
int viewteacher(string teacher[][4],int teachercount);
int updateteacher(string teacher[][4],int teachercount);
int deleteteacher(string teacher[][4],int teachercount);
int loadstudents(string student[][5]);
int loadteachers(string teacher[][4]);
int studentlogin(string student[][5],int count,string roll,string pass);
void viewattendence(string student[][5],int studentindex);
void viewgrade(string student[][5],int studentindex);
void setConsoleColor(int color);
int main()
{
string choice;
while(true)
{
system("cls");  setConsoleColor(11);
    cout << "\t  ###############################################\n";
    cout << "\t  #                                             #\n";
    cout << "\t  #      C O L L E G E   M A N A G E M E N T    #\n";
    cout << "\t  #                                             #\n";
    cout << "\t  ###############################################\n\n";
cout<<endl; setConsoleColor(13);    cout<<"\t\tPLEASE SELECT YOUR ROLE\n";
cout<<"\t\t1.LOGIN AS ADMIN\n";
cout<<"\t\t2.LOGIN AS STUDENT\n";
cout<<"\t\t3.EXIT\n";
cout<<"\t\t(ENTER YOUR CHOICE BY PRESSING 1-3):";
getline(cin,choice); //CHOICE FOR ENTERING IN ADMIN STUDENT PORTALS
if(choice=="1") //ADMIN LOGIN INTERFACE
{
string students[max_students][5];
string teachers[max_teachers][4];
int studentcount=0,teachercount=0;   
string username,password,choice;
studentcount=loadstudents(students);  //WE USED THIS FUNCTION SO BEFORE THE EXECUTION START THE PROGRAM SHOULD LOAD THE STUDENTS DATA FROM FILE
teachercount=loadteachers(teachers); //WE USED THIS FUNCTION SO BEFORE THE EXECUTION START THE PROGRAM SHOULD LOAD THE TEACHERS DATA FROM FILE
system("cls");  //SYSTEM CLS IS A WINDOW COMMAND USED TO CLEAR CONSOLE SCREEN
 setConsoleColor(5); 
cout<<"\t\t\t ADMIN LOGIN \n";  // admin login
 setConsoleColor(7); 
cout<<"\t\tENTER YOUR USERNAME:";
getline(cin,username);
cout<<"\t\tENTER YOUR PASSWORD:";
getline(cin,password);
bool loggedin;
loggedin=loginadmin(username,password);
if(loggedin)           
{                             //ADMIN DASHBOARD INTERFACE(IF THE FUNCTION RETURN TRUE THEN THIS WILL EXECUTE)
system("cls");
while(true)                   //WHILE LOOP IS USED SO THAT AFTER SUCCESSFULLY CRUD OPERATIONS THE MAIN MENU SHOULD COME AGAIN
{setConsoleColor(5);
cout<<"\t\t ADMIN DASHBOARD \n"; // dashboard
setConsoleColor(7);
cout<<"\t\tPLEASE SELECT:\n";
cout<<"\t\t1.ADD STUDENT\n";
cout<<"\t\t2.UPDATE STUDENT DETAILS\n";
cout<<"\t\t3.DELETE STUDENT\n";
cout<<"\t\t4.VIEW STUDENT DETAILS\n";
cout<<"\t\t5.ADD TEACHER\n";
cout<<"\t\t6.UPDATE TEACHER DETAILS\n";
cout<<"\t\t7.VIEW TEACHER DETAILS\n";
cout<<"\t\t8.DELETE TEACHER\n";
cout<<"\t\t9.LOGOUT\n";
cout<<"\t\tPLEASE ENTER YOUR CHOICE:";
getline(cin,choice);
if(choice=="1") //ADDSTUDENT
{
system("cls");
setConsoleColor(5);
cout<<"\t\t===============\n";
cout<<"\t\t ADD A STUDENT \n";
cout<<"\t\t===============\n\n";
setConsoleColor(7);
studentcount=addstudent(students,studentcount); //CALLED ADD FUNCTION
system("cls");
}
else if(choice=="2") //UPDATESTUDENT
{
system("cls");
setConsoleColor(5);
cout<<"\t\t UPDATE STUDENT DETAILS \n";
setConsoleColor(7);
int us;
us=updatestudent(students,studentcount);  //CALLED UPDATE STUDENT FUCTION
system("cls");
}
else if(choice=="3")  //DELETE STUDENT
{
system("cls");
setConsoleColor(5);
cout<<"\t\t DELETE A STUDENT \n";
setConsoleColor(7);
studentcount=deletestudent(students,studentcount);  //CALLED DELETE STUDENT FUNCTION
system("cls");  //COMMAND USED TWICE SO ADMIN DASHBOARD HEADING CAN BE SHOWN CLEAN
}
else if(choice=="4")  //TO VIEW STUDENNT DETAILS
{
system("cls");
setConsoleColor(5);
cout<<"\t\t VIEW A STUDENT DETAILS\n";
setConsoleColor(7);
studentcount=viewstudent(students,studentcount);
system("cls");
}
else if(choice=="5") //TO ADD A TEACHER
{
system("cls");
setConsoleColor(5);
cout<<"\t\t ADD A TEACHER \n";
setConsoleColor(7);
teachercount=addteacher(teachers,teachercount); //CALLED ADD TEACHER FUNCTION
system("cls");
}
else if(choice=="6") //TO UPDATE TEACHER DETAILS
{
system("cls");
setConsoleColor(5);
cout<<"\t\t UPDATE A TEACHER DETAILS \n";
setConsoleColor(7);
teachercount=updateteacher(teachers,teachercount);  //CALLED UPDATE TEACHER DETAILS FUNCTION
system("cls");
}
else if(choice=="7") //TO VIEW TEACHER DETAILS
{
system("cls");
setConsoleColor(5);
cout<<"\t\t\t VIEW TEACHER DETAILS \n";
setConsoleColor(7);
teachercount=viewteacher(teachers,teachercount); //CALLED VIEW TEACHER FUNCTION
system("cls");
}
else if(choice=="8") //DELETE TEACHER
{
system("cls");
setConsoleColor(5);
cout<<"\t\t DELETE TEACHER DETAILS \n";
setConsoleColor(7);
teachercount=deleteteacher(teachers,teachercount); //CALLED DELETE TEACHER FUNCTION
system("cls");
}
else if(choice=="9") //IF ADMIN PRESS LOGOUT
{
    setConsoleColor(2);
cout<<"\t\tLOGGING OUT!\n";
cout<<"\t\tPLEASE ENTER TO GO TO MAIN MENU!\n";
setConsoleColor(7);
cin.get(); //HELP TO PAUSE SO USER CAN READ THE MESSAGE
break; //EXIT ADMIN DASHBOARD LOOP
}
else
{setConsoleColor(4);
    cout<<"\tYOU ENTERED WRONG CHOICE\n PRESS ENTER TO CONTINUE!";
    cin.get();
    setConsoleColor(7);
    system("cls"); }    }   }

else if(!loggedin)  //IF USERNAME PASSWORD OF ADMIN NOT CORRECT
{
    setConsoleColor(4);
cout<<"\t\tINVALID CREDIENTIALS!\t YOU ARE NOT ADMIN\n";
cout<<"\t\tPRESS ENTER TO RETURN TO MAIN MENU";
setConsoleColor(7);
cin.get();
continue; //HELP TO RETURN TO THE TOP
}
} 
else if(choice=="2")  //STUDENT PORTAL START
{
string students[max_students][5];
system("cls");
setConsoleColor(5);
cout<<"\t\t\t STUDENT PORTAL LOGIN \n";
setConsoleColor(7);
int studentcount=0;
studentcount=loadstudents(students); 
string roll,pass;
cout<<"\t\tENTER ROLL NO:";
getline(cin,roll); 
cout<<"\t\tENTER PASSWORD:";
getline(cin,pass);
int studentindex; 
studentindex=studentlogin(students,studentcount,roll,pass); //ROLL NO AND PASSWORD PASSED TO THE STUDENT LOGIN FUNCTION
if(studentindex==-1)
{
    setConsoleColor(4);
cout<<"\t\tYOU ENTERED WRONG ROLL NO OR PASSWORD!\n";
cout<<"\t\tPRESS ENTER TO CONTINUE!\n";
setConsoleColor(7);
cin.get();
}
else
{   while(true)
    {
        string choice;
        system("cls");
        setConsoleColor(5);
        cout<<"\t\t\t    STUDENT PORTAL    \n";
        setConsoleColor(7);
        cout<<"\t\t1.VIEW ATTENDENCE DETAILS\n";
        cout<<"\t\t2.VIEW GRADE\n";
        cout<<"\t\t3.EXIT";
        cout<<"\n\t\tENTER YOUR CHOICE:";
        getline(cin,choice);
        if(choice=="1")  //VIEW ATTENDENCE(BY STUDENT)
        {
        setConsoleColor(5);
        cout<<"\t\t\t ATTENDENCE DETAILS  \n";
        setConsoleColor(7);
        viewattendence(students,studentindex); //VIEW ATTENDENCE FUCTION CALLED
        }
        else if(choice=="2") //VIEW GRADE(BY STUDENT)
        {
            system("cls");
         setConsoleColor(5);
         cout<<"\t\t\t     GRADE DETAILS    \n";
         setConsoleColor(7);
        viewgrade(students,studentindex); //VIEW GRADE FUNCTION CALLED
        
        }
        else if(choice=="3") //TO EXIT FROM STUDENT PORTAL
        {
            setConsoleColor(2);
            cout<<"\t\t\nPRESS ENTER TO CONTINUE";
            setConsoleColor(7);
            cin.get();
            break;
        }
        else //IF STUDENT PRESS ANYTHING ELSE 1 2 3 4 5
        {
            setConsoleColor(4);
        cout<<"\t\tYOU ENTERED WRONG OPTION! \nPRESS ENTER TO CONTINUE";
        setConsoleColor(7);
        cin.get();
        }
    }
}   
}
else if(choice=="3") //IF USER PRESS 3 THE PROGRAM ENDS
{
    setConsoleColor(2);
cout<<"\t\t\tTHANK YOU!\n";
setConsoleColor(7);
break;
}
else  //IF USER PRESS ANYTHING RATHER THAN 1 2 3
{
system("cls");
setConsoleColor(4);
cout<<"\t\tPLEASE SELECT ONLY FROM 1-3\n";
cin.ignore();
cout<<"\t\tPRESS ENTER TO GO BACK TO MAIN MENU\n";
setConsoleColor(7);
cin.get();
}
} 
}
//=======ALL FUNCTIONS START FROM HERE 
bool loginadmin(string user,string pass) //ADMIN LOGIN FUNCTION
{
string adminuser="ADMIN"; //HARD CODE FOR ADMIN LOGIN AS ADMIN OF THE SYSTEM IS ONLY ONE
string password="COLLEGE";
if(adminuser==user&&password==pass)
return true;   // RETURNS TRUE IF CRITERIA MEET
else
return false;  // RETURNS FALSE IF CRITERIA DOES NOT MEET
}

int addstudent(string student[][5],int studentcount)  //FUNCTION TO ADD STUDENT BY ADMIN
{
if(studentcount>=max_students) //FIRST CHECK IF STUDENT NOT GREATER THEN MAX STUDENTS
{setConsoleColor(4);
    cout<<"\n\t\tSTUDENTS LIST IS FULL!\n";
    return studentcount;
    setConsoleColor(7);
}
string rollno,grade,name,attendence,password;
cout<<"\n\t\tENTER ROLL NO:";
getline(cin,rollno);
cout<<"\n\t\tENTER PASSWORD:";
getline(cin,password);
cout<<"\n\t\tENTER NAME:";
getline(cin,name);
cout<<"\n\t\tENTER ATTENDENCE:";
getline(cin,attendence);
cout<<"\n\t\tENTER THE GRADE:";
getline(cin,grade);
student[studentcount][0]=rollno;
student[studentcount][1]=password;
student[studentcount][2]=name;
student[studentcount][3]=attendence;
student[studentcount][4]=grade;
studentcount++;
fstream file; //START WRITING INFORMATION INTO THE FILE
file.open("ADDSTUDENT.txt",ios::app);
if(!file)
{
    setConsoleColor(2);
    cout<<"\n\t\tERROR OPENING FILE!";
    return studentcount-1;
    setConsoleColor(7);
}
file<<rollno<<endl;
file<<password<<endl;
file<<name<<endl;
file<<attendence<<endl;
file<<grade<<endl;
file.close();
setConsoleColor(5);
cout<<"\n\t\tSTUDENT ADDED SUCCESSFULLY!";
setConsoleColor(7);
cout<<"\n\t\tSTUDENT LOGIN ID:"<<rollno;
cout<<"\n\t\tSTUDENT LOGIN PASSWORD:"<<password;
setConsoleColor(5);
cout<<"\n\t\tPRESS ENTER TO GO TO ADMIN DASHBOARD!";
setConsoleColor(7);
cin.get();
return studentcount; //RETURN FINAL STUDENT COUNT
}
int updatestudent(string student[][5],int studentcount) //FUNCTION TO UPDATE STUDENT DETIALS
{
    string roll;
    int index=-1;
if(studentcount==0)
{
    setConsoleColor(4);
    cout<<"\n\t\tPLEASE ENTER DATA OF STUDENTS FIRST!\n";
    setConsoleColor(7);
    cin.get();
    return studentcount;
}

cout<<"\t\tPLEASE ENTER STUDENT ROLL NO:";
getline(cin,roll);
for(int i=0;i<studentcount;i++)
{
    if(student[i][0]==roll) //CHECK THE SPECIFIC FIELD
    {
    index=i;
    break;
    }
}
if(index==-1)
{
    setConsoleColor(4);
cout<<"\t\tSTUDENT NOT FOUND!";
setConsoleColor(7);
cin.get();
return studentcount;
}
string field;
cout<<"\t\tWHICH FIELD YOU WANT TO UPDATE?\n";
cout<<"\t\t1.ROLL NO\n";
cout<<"\t\t2.PASSWORD\n";
cout<<"\t\t3.NAME\n";
cout<<"\t\t4.ATTENDENCE\n";
cout<<"\t\t5.GRADE\n";
cout<<"\t\t6.CANCEL\n";
cout<<"\t\tPLEASE ENTER YOUR CHOICE:";
getline(cin,field);
if(field=="1") //TO UPDATE NEW ROLL NO
{
    string newrollno;
    cout<<"\n\t\tPLEASE ENTER NEW ROLL NO:";
    getline(cin,newrollno);
    student[index][0]=newrollno;
}
else if(field=="2") //TO UPDATE NEW PASSWORD
{
     string newpass;
    cout<<"\n\t\tPLEASE ENTER NEW PASSWORD:";
    getline(cin,newpass);
    student[index][1]=newpass;
}
else if(field=="3")       //TO UPDATE NEW NAME
{
     string newname;
    cout<<"\n\t\tPLEASE ENTER NEW NAME:";
    getline(cin,newname);
    student[index][2]=newname;
}
else if(field=="4")     //TO UPDATE NEW ATTENDENCE
{
     string newattendence;
    cout<<"\n\t\tPLEASE ENTER NEW ATTENDENCE:";
    getline(cin,newattendence);
    student[index][3]=newattendence;
}
else if(field=="5")      //TO ENTER NEW GRADE
{
     string newgrade;
    cout<<"\n\t\tPLEASE ENTER NEW GRADE:";
    getline(cin,newgrade);
    student[index][4]=newgrade;
}
else if(field=="6")   //IF USER CANCEL UPDATE
{
    setConsoleColor(4);
    cout<<"\n\t\tUPDATE CANCELLED!\n";
    cin.get();
    setConsoleColor(7);
    return studentcount;
}
else  //IF USER ENTERED WRONG INPUT
{
    setConsoleColor(4);
    cout<<"\n\t\tYOU ENTERED WRONG OPTION!\n";
    setConsoleColor(7);
    cin.get();
    return studentcount;
}
fstream file;   //PROCESS TO STORE UPDATED DATA INTO THE FILE
file.open("ADDSTUDENT.txt",ios::out);
for(int i=0;i<studentcount;i++)
{
    for(int j=0;j<5;j++)
    file<<student[i][j]<<endl;
}
file.close();
setConsoleColor(2);
cout<<"\t\tFIELD UPDATED SUCCESSFULLY"<<endl;
cout<<"\t\tPRESS ENTER TO RETURN"<<endl;
setConsoleColor(7);
cin.get();
return studentcount;
}
int deletestudent(string student[][5],int studentcount) //FUNCTION TO DELETE STUDENT DETAILS
{
    if(studentcount==0)
    {
        setConsoleColor(4);
        cout<<"\t\tThere is no student to delete!"<<endl;
        setConsoleColor(7);
        cin.get();
        return studentcount;
    }
    string rollno;
    cout<<"\tENTER ROLL NO OF STUDENT TO DELETE:";
    getline(cin,rollno);
    int index=-1;
    for(int i=0;i<studentcount;i++)
    {
        if(student[i][0]==rollno)
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        setConsoleColor(4);
        cout<<"\n\t\tSTUDENT NOT FOUND!";
        setConsoleColor(7);
        cin.get();
        return studentcount;
    }
    for(int i=index;i<studentcount-1;i++)
    {
        for(int j=0;j<5;j++)
        {
            student[i][j]=student[i+1][j];  //SHIFT NEXT STUDENT TO DELETED STUDENT PLACE
        }
    }
    studentcount--;
    fstream file;
    file.open("ADDSTUDENT.txt",ios::out);
    for(int i=0;i<studentcount;i++)
    {
        for(int j=0;j<5;j++)
        {
            file<<student[i][j]<<endl; 
        }
    }
    file.close();
    setConsoleColor(2);
    cout<<"\t\tSTUDENT DELETED SUCCESSFULLY!\n";
    cout<<"\t\tPRESS ENTER TO RETURN!\n";
    setConsoleColor(7);
    cin.get();
    return studentcount;
}
int viewstudent(string student[][5],int studentcount) //VIEW STUDENT FUNCTION
{

 if(studentcount==0)
 {
    setConsoleColor(4);
    cout<<"NO STUDENT FOUND!";
    setConsoleColor(7);
    cin.get();
    return studentcount;
 }   string rollno;
 cout<<"\t\tPLEASE ENTER ROLL NO OF STUDENT TO VIEW DETAILS:";
 getline(cin,rollno);
 int index=-1;
 for(int i=0;i<studentcount;i++)
 {
    if(student[i][0]==rollno) //TO CHECK IF STUDENT EXSIST
    {
        index=i;
    }
 }
 if(index==-1) //IF NOTHING HAPPENS INDEX VALUE IS -1 SO NO STUDENT FOUND
 {
    setConsoleColor(4);
    cout<<"\t\t\nNO STUDENT NOT FOUND!";
    cout<<"\t\t\nPRESS ENNTER TO CONTINUE";
    setConsoleColor(7);
    cin.get();
    return studentcount;
 }
 else
 {
    setConsoleColor(5);
cout<<"\n\t\t\t=====STUDENT DETAILS=====\n\n";
setConsoleColor(7);
 cout<<"\t\tROLL NO:"<<student[index][0]<<endl;
 cout<<"\t\tPASSWORD:"<<student[index][1]<<endl;
 cout<<"\t\tNAME:"<<student[index][2]<<endl;
 cout<<"\t\tATTENDENCE:"<<student[index][3]<<endl;
 cout<<"\t\tGRADE:"<<student[index][4]<<endl;
 cout<<"\t\tPRESS ENTER TO RETURN!";
 cin.get();
 return studentcount;
 }
}
//TEACHER RELATED FUNCTIONS
int addteacher(string teacher[][4],int teachercount) //ADD TEACHER TO FILE
{
    if(teachercount>=max_students)
{
    setConsoleColor(4);
    cout<<"\n\t\tTEACHER LIST IS FULL!\n";
    setConsoleColor(7);
    return teachercount;
}
string ID,CLASS,name,SALARY;
cout<<"\n\t\tENTER ID OF TEACHER:";
getline(cin,ID);
cout<<"\n\t\tENTER NAME:";
getline(cin,name);
cout<<"\n\t\tENTER CLASS:";
getline(cin,CLASS);
cout<<"\n\t\tENTER SALARY:";
getline(cin,SALARY);
teacher[teachercount][0]=ID;  //ONE BY ONE INFORMATION STORE IN ARRAY
teacher[teachercount][1]=name;
teacher[teachercount][2]=CLASS;
teacher[teachercount][3]=SALARY;
teachercount++;
fstream file;   //FILE OPENING PROCESS TO WRITE TEACHER DETAILS
file.open("ADDTEACHER.txt",ios::app);
if(!file)
{
    setConsoleColor(4);
    cout<<"\n\t\tERROR OPENING FILE!";
    setConsoleColor(7);
    return teachercount-1;
}
file<<ID<<endl;
file<<name<<endl;
file<<CLASS<<endl;
file<<SALARY<<endl;
file.close();
setConsoleColor(2);
cout<<"\n\t\tTEACHER ADDED SUCCESSFULLY!";
cout<<"\n\t\tPRESS ENTER TO GO TO ADMIN DASHBOARD!";
setConsoleColor(7);
cin.get();
return teachercount;
}
int updateteacher(string teacher[][4],int teachercount) //FUNCTION TO UPDATE TEACHER DETIALS
{
    string id;
    int index=-1;
if(teachercount==0)
{
    setConsoleColor(4);
    cout<<"\n\t\tPLEASE ENTER DATA OF TEACHERS FIRST!\n";
    setConsoleColor(7);
    cin.get();
    return teachercount;
}

cout<<"\t\tPLEASE ENTER TEACHER ID:";
getline(cin,id);
for(int i=0;i<teachercount;i++)
{
    if(teacher[i][0]==id) //CHECK THE SPECIFIC FIELD
    {
    index=i;
    break;
    }
}
if(index==-1)
{
    setConsoleColor(4);
cout<<"\t\tTEACHER NOT FOUND!";
setConsoleColor(7);
cin.get();
return teachercount;
}
string field;
cout<<"\t\tWHICH FIELD YOU WANT TO UPDATE?\n";
cout<<"\t\t1.ID\n";
cout<<"\t\t2.NAME\n";
cout<<"\t\t3.CLASS\n";
cout<<"\t\t4.SALARY\n";
cout<<"\t\t5.CANCEL\n";
cout<<"\t\tPLEASE ENTER YOUR CHOICE:";
getline(cin,field);
if(field=="1") //TO UPDATE NEW ID
{string newID;
    cout<<"\n\t\tPLEASE ENTER NEW ID:\n";
    getline(cin,newID);
    teacher[index][0]=newID;
}
else if(field=="2") //TO UPDATE NEW NAME
{
     string newname;
    cout<<"\t\tPLEASE ENTER NEW NAME:";
    getline(cin,newname);
    teacher[index][1]=newname;
}
else if(field=="3")       //TO UPDATE NEW CLASS
{
     string newclass;
    cout<<"\n\t\tPLEASE ENTER NEW CLASS:";
    getline(cin,newclass);
    teacher[index][2]=newclass;
}
else if(field=="4")     //TO UPDATE NEW ATTENDENCE
{
     string newsalary;
    cout<<"\n\t\tPLEASE ENTER NEW SALARY:";
    getline(cin,newsalary);
    teacher[index][3]=newsalary;
}
else if(field=="5")   //IF USER CANCEL UPDATE
{
    cout<<"\n\t\tUPDATE CANCELLED!";
    cin.get();
    return teachercount;
}
else  //IF USER ENTERED WRONG INPUT
{
    setConsoleColor(4);
    cout<<"\n\t\tYOU ENTERED WRONG OPTION!";
    setConsoleColor(7);
    cin.get();
    return teachercount;
}
fstream file;   //PROCESS TO STORE UPDATED DATA INTO THE FILE
file.open("ADDTEACHER.txt",ios::out);
for(int i=0;i<teachercount;i++)
{
    for(int j=0;j<4;j++)      
    file<<teacher[i][j]<<endl;
}
file.close();
setConsoleColor(2);
cout<<"\t\tFIELD UPDATED SUCCESSFULLY"<<endl;
cout<<"\t\tPRESS ENTER TO RETURN"<<endl;
setConsoleColor(7);
cin.get();
return teachercount;
}
int viewteacher(string teacher[][4],int teachercount) //VIEW TEACHER DETAILS
{
 if(teachercount==0) //CHECK IF THERE IS NO TEACHER IN THE FILE
 {
    setConsoleColor(4);
    cout<<"NO TEACHER FOUND!";
    setConsoleColor(7);
    cin.get();
    return teachercount;
 }   
 string ID;
 cout<<"\t\tPLEASE ENTER ID OF TEACHER TO VIEW DETAILS:";
 getline(cin,ID);
 int index=-1;
 for(int i=0;i<teachercount;i++)
 {
    if(teacher[i][0]==ID)
    {
        index=i;
    }
 }
 if(index == -1) //IF NOTHING FOUND INDEX REMAIN -1
{
    setConsoleColor(4);
    cout<<"TEACHER NOT FOUND!";
    setConsoleColor(7);
    cin.get();
    cout<<"\n\t\tPRESS ENTER TO CONTINUE!";
    return teachercount;
     
}
 setConsoleColor(2);
 cout<<"\n\t\t\t=====TEACHER DETAILS=====\n\n";
 setConsoleColor(7);
 cout<<"\t\tID:"<<teacher[index][0]<<endl;
 cout<<"\t\tNAME:"<<teacher[index][1]<<endl;
 cout<<"\t\tCLASS:"<<teacher[index][2]<<endl;
 cout<<"\t\tSALARY:"<<teacher[index][3]<<endl;
 cout<<"\t\tPRESS ENTER TO RETURN!";

 cin.get();
 return teachercount;   
}
int deleteteacher(string teacher[][4],int teachercount) //DELETE TEACHER DETAILS
{
    if(teachercount==0)
    {
        cout<<"\t\tThere is no teacher to delete!"<<endl;
        cin.get();
        return teachercount;
    }
    string ID;
    cout<<"\t\tENTER ID OF TEACHER TO DELETE:"; getline(cin,ID);
    int index=-1;
    for(int i=0;i<teachercount;i++)
    {
        if(teacher[i][0]==ID)
        {    index=i;  //TO CHECK WHICH TEACHER IS SELECTED
            break; }
        }     if(index==-1) {
        setConsoleColor(4);
        cout<<"\n\t\tTEACHER NOT FOUND!";
        setConsoleColor(7);
        cin.get();
        return teachercount;
    }
    for(int i=index;i<teachercount-1;i++)
    {
        for(int j=0;j<4;j++)
        {
            teacher[i][j]=teacher[i+1][j]; //MOVE NEXT TEACHER IN PLACE OF EXSISTING TEACHER
        } }
    teachercount--;  //REDUCE THE TEACHER COUNT
    fstream file;
    file.open("ADDTEACHER.txt",ios::out);
    for(int i=0;i<teachercount;i++)
    {
        for(int j=0;j<4;j++)
        {
            file<<teacher[i][j]<<endl;
        } }
    file.close();
    setConsoleColor(2);
    cout<<"\t\tTEACHER DELETED SUCCESSFULLY!\n";
    cout<<"\t\tPRESS ENTER TO RETURN!\n";
    setConsoleColor(7);
    cin.get();
    return teachercount;
}   //THE ADMIN FUNCTIONS END HERE
int loadstudents(string student[][5]) //HELP TO LOAD THE 2D ARRAY USED IN WHOLE PROGRAM
{
    fstream file;
    file.open("ADDSTUDENT.txt");
    if(!file)
    {
        setConsoleColor(4);
        cout<<"\t\t\nFILE NOT FOUND!\n";
        setConsoleColor(7);
        return 0;
    }
    int count=0;
    while(true)
    {
        string loadrollno,loadpass,loadname,loadattendence,loadgrade;
        getline(file,loadrollno);
        getline(file,loadpass);
        getline(file,loadname);
        getline(file,loadattendence);
        getline(file,loadgrade);
        if(loadrollno=="" || loadpass=="" ||loadname==""||loadattendence==""||loadgrade=="" ) //STOP LOOP IF ANY FILE MISSING
        break;
        student[count][0]=loadrollno;
        student[count][1]=loadpass;
        student[count][2]=loadname;
        student[count][3]=loadattendence;
        student[count][4]=loadgrade;
        count++;
        if(count>=max_students)
        break;
    }
    file.close();
    return count;
}
int loadteachers(string teacher[][4])   // LOAD TEACHERS FROM FILE
{
    fstream file;
    file.open("ADDTEACHER.txt");
    if(!file)
    {
        setConsoleColor(4);
        cout << "\n\t\tFILE NOT FOUND!\n";
        setConsoleColor(7);
        return 0;
    }
    int count = 0;
    while(true)
    {
        string id,name,subject,salary;
        getline(file,id);
        getline(file,name);
        getline(file,subject);
        getline(file,salary);
        if(id==""||name==""||subject==""||salary=="")
            break;
        teacher[count][0] = id;
        teacher[count][1] = name;
        teacher[count][2] = subject;
        teacher[count][3] = salary;
        count++;
        if(count >= max_teachers)
            break;
    }
    file.close();
    return count;
}
int studentlogin(string student[][5],int count,string roll,string pass) // STUDENT LOGIN FUNCTION
{int index=-1;
    for(int i=0;i<count;i++)
    {
        if(student[i][0]==roll&&student[i][1]==pass)
        {
            return i;
        }
    }
    return -1;
}
void viewattendence(string student[][5],int studentindex) //VIEW ATTENDENCE )(BY STUDENT) (ONLY VIEW)
{
    system("cls");
    setConsoleColor(5);
     cout<<"\t\t\t ATTENDENCE DETAILS  \n";
     setConsoleColor(7);
     cout<<"\t\tYOUR ATTENDENCE IS:"<<student[studentindex][3]<<"%"<<endl;
     setConsoleColor(2);
     cout<<"\n\t\tPRESS ENTER TO RETURN!";
     setConsoleColor(7);
     cin.get(); }
void viewgrade(string student[][5],int studentindex) //VIEW GRADE (BY STUDENT) (ONLY VIEW)
{
     cout<<"\n\t\t YOUR GRADE IS:"<<student[studentindex][4];
     setConsoleColor(2);
     cout<<"\n\n\t\tPRESS ENTER TO RETURN TO STUDENT PORTAL!";  setConsoleColor(7);
     cin.get();  }
void setConsoleColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//PROGRAM END
