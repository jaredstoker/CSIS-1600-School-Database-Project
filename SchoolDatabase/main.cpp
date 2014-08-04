#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
int slines = 0;
int tlines = 0;

void getdbSize()
{

    std::string sline, tline;
    std::ifstream sfile("students.txt");
    std::ifstream tfile("teachers.txt");

    while (std::getline(sfile, sline))
        ++slines;
    while (std::getline(tfile, tline))
        ++tlines;


}

struct Students{
    string fname,lname;
    int year;
    int active;
    int class1, class2, class3, class4;
    string grade1, grade2, grade3, grade4;
}sdb[10];
struct Teachers{
    string fname, lname;
    int class1, class2, class3, class4;
}tdb[10];
struct Courses{
    string course;
}cdb[10];


using namespace std;
void studentMenu();
void adminMenu();
void defaultMenu();
void teacherMenu();
void newStudent();
void addDropClass();
void viewClass();
void viewGrades();
//Load Student Database
void classes_load()
{

    ifstream classesInFile("classes.txt");

    if(!classesInFile)
    {
        cout<<"Cannot load file"<<endl;
        return;
    }
    else
    {
        for(int i = 0; i < sizeof(cdb)/sizeof(cdb[0]); i++)
        {
            classesInFile>>
            cdb[i].course;

        }
        cout <<"All classes have been successfully loaded"<<endl;

        classesInFile.close();
    }
}

void sdb_load()
{

    ifstream sdatabaseInFile("students.txt");


    if(!sdatabaseInFile)
    {
        cout<<"Cannot load file"<<endl;
        return;
    }
    else
    {

        for(int i = 0; i < sizeof(sdb)/sizeof(sdb[0]); i++)
        {
            sdatabaseInFile>>
            sdb[i].fname>>
            sdb[i].lname>>
            sdb[i].year>>
            sdb[i].active>>
            sdb[i].class1>>
            sdb[i].class2>>
            sdb[i].class3>>
            sdb[i].class4>>
            sdb[i].grade1>>
            sdb[i].grade2>>
            sdb[i].grade3>>
            sdb[i].grade4;
            //cout <<"Student no "<<i<<" loaded"<<endl;
        }
        cout <<"All students have been successfully loaded"<<endl;
        sdatabaseInFile.close();
    }
}
void sdb_save()
{
    ofstream sdatabaseOutFile("students.txt");
    if(!sdatabaseOutFile)
    {
        cout<<"Cannot save file"<<endl;
        return;
    }
    else
    {
        for(int i = 0; i < sizeof(sdb)/sizeof(sdb[0]); i++)
        {
            sdatabaseOutFile<<
            sdb[i].fname<<
            sdb[i].lname<<
            sdb[i].year<<
            sdb[i].active<<
            sdb[i].class1<<
            sdb[i].class2<<
            sdb[i].class3<<
            sdb[i].class4<<
            sdb[i].grade1<<
            sdb[i].grade2<<
            sdb[i].grade3<<
            sdb[i].grade4;
            cout <<"Student no "<<i<<"saved"<<endl;
        }
        cout <<"All students have been successfully saved"<<endl;
        sdatabaseOutFile.close();
    }
}
void tdb_load()
{

    ifstream tdatabaseInFile("teachers.txt");


    if(!tdatabaseInFile)
    {
        cout<<"Cannot save file"<<endl;
        return;
    }
    else
    {

        for(int i = 0; i < sizeof(tdb)/sizeof(tdb[0]); i++)
        {
            tdatabaseInFile>>
            tdb[i].fname>>
            tdb[i].lname>>
            sdb[i].class1>>
            sdb[i].class2>>
            sdb[i].class3>>
            sdb[i].class4;
            //cout <<"Teacher no "<<i<<"loaded"<<endl;
        }
        cout <<"All teachers have been successfully loaded"<<endl;
        tdatabaseInFile.close();
    }
}
void tdb_save()
{
    ofstream tdatabaseOutFile("teachers.txt");
    if(!tdatabaseOutFile)
    {
        cout<<"Cannot save file"<<endl;
        return;
    }
    else
    {
        for(int i = 0; i < sizeof(tdb)/sizeof(tdb[0]); i++)
        {
            tdatabaseOutFile<<
            tdb[i].fname<<
            tdb[i].lname<<
            tdb[i].class1<<
            tdb[i].class2<<
            tdb[i].class3<<
            tdb[i].class4;
            cout <<"Teacher no "<<i<<"saved"<<endl;
        }
        cout <<"All teachers have been successfully saved"<<endl;
        tdatabaseOutFile.close();
    }
}
//register as a new student
void newStudent()
{
    string fname;
    string lname;
    char response;

    cout << "Enter your first name: ";
    cin >> fname;
    cout << "Enter your last name: ";
    cin >> lname;
    //display the input to user and give user the choice if it is correct or not
    cout << "Your name is " << fname << " " << lname << ".\n"
         << "Is this correct?(y or n): ";
    cin >> response;//user response to yes or no

    //if it is correct then a message display to let user know they can register for classes
    if(tolower(response) == 'y')
    {
        //outFile << fname << " " << lname;
        cout << "Now you can register for classes!" << endl;
    }
    //if it is not correct then user can input their names again
    if(tolower(response) == 'n')
    {
        //this while loop while continue to run as long as response is no or n
        while(response != 'y')
        {
            cout << "Enter your first name: ";
            cin >> fname;
            cout << "Enter your last name: ";
            cin >> lname;
            //display the input to user and give user the choice if it is correct or not
            cout << "Your name is " << fname << " " << lname << ".\n"
                 << "Is this correct?(y or n): ";
            cin >> response;
            if(response == 'y')
            {
                sdb[slines+1].fname = fname;
                sdb[slines+1].lname = lname;
            }
        }
    }
}
//add or drop classes(student)
/*void addDropClass()
{
    char input;
    cout << "Do you want to add or drop class?\n"
         << "To add class enter (a) and to drop class enter (d) (a or d): ";
    cin >> input;
    if(input == 'a')
    {
        int numb;
        char choice;
        cout << "Here is the list of classes offer this semester: " << endl;
        //here will be the classes file
        cout << "Please enter the number of the class you want to take: ";
        cin >> numb;
        //I will put in if-else statement here to get the class that user chose

        //the for loop here is to limit the classes student can take to 4
        for(int i = 0; i < 3; i++)
        {
            cout << "Would you like to add another class(y or n): ";
            cin >> choice;
            if(choice == 'y')
            {
                //redisplay the class again
                cout << "Enter the number of the class you want to take: ";
                cin >> numb;
                //if-else statement here to get the class user chose
            }
            if(choice == 'n')
            {
                cout << "Now you can check your schedule!" << endl;
                break;
            }
        }

        if(input == 'd')
        {
            ifstream inFile;
            int cnum;
            inFile.open();
            if(inFile.fail())
            {
                cout << "You have not yet register for any classes!" << endl;
                exit(1);
            }

            cout << "Which class would you like to drop(enter the number): ";
            cin >> cnum;
            //here would be codes to delete the class of student choice
        }


    }
}
*/
//view class schedule
void viewClass()
{
    //after all the add or drop classes the class schedule will display
}
//view grades
void viewGrades()
{
    //the grades will be display with the file upload by the teacher
}
void teacherMenu()
{
    {
        char selection;

           do
           {//menu
               cout << "  Teacher Menu - Choose your role:\n";
               cout << "  ====================================\n";
               cout << "  1.  View Class Schedule\n";
               cout << "  2.  View Student Schedule\n";
               cout << "  3.  Assign Grades\n";
               cout << "  4.  Back to Main Menu\n";
               cout << "\n";
               cout << "  5.  Exit\n";
               cout << "  ====================================\n";
               cout << "  Enter your selection: ";
               cin >> selection;
               cout << endl;

               switch (selection)
               {
                   case '1':
                       //View Class Schedule
                       studentMenu();
                       break;

                   case '2':
                       //View Student Schedule
                       teacherMenu();
                       break;
                   case '3':
                       //Assign Grades
                       adminMenu();
                       break;
                   case '4':
                       defaultMenu();
                       break;
                   case '5':
                       cout << "Goodbye.\n";
                       selection = 0;
                       break;

                   default: cout <<selection << "is not a valid menu item.\n";
                   cout << endl;
               }
           }while (selection != 0 );
    }
}

void studentMenu()
{
    {
        char selection;

           do
           {//menu
               cout << "  Student Menu:\n";
               cout << "  ====================================\n";
               cout << "  1.  Register\n";
               cout << "  2.  Add/Remove Classes\n";
               cout << "  3.  View Class Schedule\n";
               cout << "  4.  View Grades\n";
               cout << "  5.  Back to Main Menu\n";
               cout << "\n";
               cout << "  6.  Exit\n";
               cout << "  ====================================\n";
               cout << "  Enter your selection: ";
               cin >> selection;
               cout << endl;

               switch (selection)
               {
                   case '1':
                       //Register
                       studentMenu();
                       break;

                   case '2':
                       //Add/Remove Classes
                       teacherMenu();
                       break;
                   case '3':
                       //View Class Schedule
                       adminMenu();
                       break;
                   case '4':
                       //View Grades
                       adminMenu();
                       break;
                   case '5':
                       defaultMenu();
                       break;
                   case '6':
                       cout << "Goodbye.\n";
                       selection = 0;
                       break;

                   default: cout <<selection << "is not a valid menu item.\n";
                   cout << endl;
               }
           }while (selection != 0 );
    }
}

void adminMenu()
{
    {
        char selection;

           do
           {//menu
               cout << "  Admin Menu:\n";
               cout << "  ====================================\n";
               cout << "  1.  Add/Remove Students\n";
               cout << "  2.  Add/Remove Teachers\n";
               cout << "  3.  Approve/Reject Students\n";
               cout << "  4.  Back to Main Menu\n";
               cout << "\n";
               cout << "  5.  Exit\n";
               cout << "  ====================================\n";
               cout << "  Enter your selection: ";
               cin >> selection;
               cout << endl;

               switch (selection)
               {
                   case '1':
                       //Add/Remove Students
                       studentMenu();
                       break;

                   case '2':
                       //Add/Remove Teachers
                       teacherMenu();
                       break;
                   case '3':
                       //Approve/Reject Students
                       adminMenu();
                       break;
                   case '4':
                       defaultMenu();
                       break;
                   case '5':
                       cout << "Goodbye.\n";
                       selection = 0;
                       break;

                   default: cout <<selection << "is not a valid menu item.\n";
                   cout << endl;
               }
           }while (selection != 0 );
    }
}

void defaultMenu()
{
    {
        char selection;

           do
           {//menu
               cout << "  Main Menu - Choose your role:\n";
               cout << "  ====================================\n";
               cout << "  1.  Student.\n";
               cout << "  2.  Teacher\n";
               cout << "  3.  Admin\n";
               cout << "\n";
               cout << "  4.  Exit\n";
               cout << "  ====================================\n";
               cout << "  Enter your selection: ";
               cin >> selection;
               cout << endl;

               switch (selection)
               {
                   case '1':
                       //Student
                       studentMenu();
                       break;

                   case '2':
                       //Teacher
                       teacherMenu();
                       break;
                   case '3':
                       //Admin
                       adminMenu();
                       break;
                   case '4':
                       cout << "Goodbye.\n";
                       selection = 0;
                       break;

                   default: cout <<selection << "is not a valid menu item.\n";
                   cout << endl;
               }
           }while (selection != 0 );
    }
}


int main()
{
    getdbSize();

    sdb_load();
    tdb_load();
    classes_load();
    //Test print the database after initialization
    /*for(int j = 0; j < 5; j++)
        {
        cout<<sdatabase[j].fname<<sdatabase[j].lname;
        cout<<tdatabase[j].fname<<tdatabase[j].lname;
        }
    */
   defaultMenu();
}

