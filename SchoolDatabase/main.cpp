#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;
struct students{
    string fname,lname;
    int year;
    int active;
    int class1, class2, class3, class4;
    string grade1, grade2, grade3, grade4;
}sdatabase[10];
struct teachers{
    string fname, lname;
    int class1, class2, class3, class4;
}tdatabase[3];



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
void sdatabase_load()
{
    ifstream sdatabaseInFile;
    sdatabaseInFile.open("sdatabase.txt");
    if(!sdatabaseInFile)
    {
        cout<<"Cannot load file"<<endl;
        return;
    }
    else
    {
        for(int i = 0; i < sizeof sdatabase; i++)
        {
            sdatabaseInFile>>
            sdatabase[i].fname<<
            sdatabase[i].lname<<
            sdatabase[i].year<<
            sdatabase[i].active<<
            sdatabase[i].class1<<
            sdatabase[i].class2<<
            sdatabase[i].class3<<
            sdatabase[i].class4<<
            sdatabase[i].grade1<<
            sdatabase[i].grade2<<
            sdatabase[i].grade3<<
            sdatabase[i].grade4<<
            cout <<"Student no "<<i<<"loaded"<<endl;
        }
        cout <<"All students have been successfully loaded"<<endl;
        sdatabaseInFile.close();
    }
}
void sdatabase_save()
{
    ofstream sdatabaseOutFile;
    sdatabaseOutFile.open("sdatabase.txt");
    if(!sdatabaseOutFile)
    {
        cout<<"Cannot load file"<<endl;
        return;
    }
    else
    {
        for(int i = 0; i < sizeof sdatabase; i++)
        {
            sdatabaseInFile>>
            sdatabase[i].fname<<
            sdatabase[i].lname<<
            sdatabase[i].year<<
            sdatabase[i].active<<
            sdatabase[i].class1<<
            sdatabase[i].class2<<
            sdatabase[i].class3<<
            sdatabase[i].class4<<
            sdatabase[i].grade1<<
            sdatabase[i].grade2<<
            sdatabase[i].grade3<<
            sdatabase[i].grade4<<
            cout <<"Student no "<<i<<"saved"<<endl;
        }
        cout <<"All students have been successfully saved"<<endl;
        sdatabaseInFile.close();
    }
}
//register as a new student
void newStudent()
{
    string fname;
    string lname;
    ofstream outFile;
    char response;
    //write to file called student1.txt
    outFile.open("student1.txt");
    if(outFile.fail())
    {
        cout << "student1.txt was not opened successfully." << endl;
        exit(1);
    }

    outFile << "Student name" << setw(12)
            << "Grade 1" << setw(12)
            << "Grade 2" << setw(12)
            << "Grade 3" << setw(12)
            << "Grade 4" << setw(12)
            << "Wt Ave" << endl;
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
        outFile << fname << " " << lname;
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
                outFile << fname << " " << lname;
            }
        }
    }
}
//add or drop classes(student)
void addDropClass()
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
    sdatabase[0].fname = "Jared";
    sdatabase[0].lname = "Stoker";
    sdatabase[0].year = 3;
    sdatabase[0].year = 1;
    sdatabase[0].class1 = 1;
    sdatabase[0].class2 = 2;
    sdatabase[0].class3 = 3;
    sdatabase[0].class4 = 4;
    sdatabase[1].fname = "Kirby";
    sdatabase[1].lname = "Wood";
    sdatabase[1].year = 3;
    sdatabase[1].class1 = 1;
    sdatabase[1].class2 = 2;
    sdatabase[1].class3 = 3;
    sdatabase[1].class4 = 4;
    sdatabase[1].year = 2;
    sdatabase[1].class1 = 2;
    sdatabase[1].class2 = 4;
    sdatabase[1].class3 = 6;
    sdatabase[1].class4 = 8;
    sdatabase[2].fname = "Chanh";
    sdatabase[2].lname = "Lam";
    sdatabase[2].year = 3;
    sdatabase[2].class1 = 1;
    sdatabase[2].class2 = 2;
    sdatabase[2].class3 = 3;
    sdatabase[2].class4 = 4;
    sdatabase[2].class2 = 3;
    sdatabase[2].class3 = 5;
    sdatabase[2].class4 = 7;
    sdatabase[3].fname = "Sachith";
    sdatabase[3].lname = "Abayakoon";
    sdatabase[3].year = 3;
    sdatabase[3].class1 = 1;
    sdatabase[3].class2 = 2;
    sdatabase[3].class3 = 3;
    sdatabase[3].class4 = 4;
    sdatabase[3].year = 4;
    sdatabase[3].class1 = 10;
    sdatabase[3].class2 = 9;
    sdatabase[3].class3 = 8;
    sdatabase[3].class4 = 7;
    tdatabase[0].fname = "Benjamin";
    tdatabase[0].lname = "Franklin";
    tdatabase[0].class1 = 4;
    tdatabase[0].class2 = 5;
    tdatabase[0].class3 = 6;
    tdatabase[0].class4 = 7;
    tdatabase[0].fname = "Woody";
    tdatabase[0].lname = "Harrelson";
    tdatabase[0].class1 = 1;
    tdatabase[0].class2 = 2;
    tdatabase[0].class3 = 3;
    tdatabase[0].class4 = 8;
    tdatabase[0].fname = "Barrack";
    tdatabase[0].lname = "Obama";
    tdatabase[0].class1 = 9;
    tdatabase[0].class2 = 10;


    for(int j = 0; j < 5; j++)
        {
        cout<<sdatabase[j].fname<<sdatabase[j].lname;
        }
   defaultMenu();
}

