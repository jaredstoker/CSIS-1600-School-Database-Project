#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int slines = 0;
int tlines = 0;
string line;
int currentNumberOfStudents = 0;
int currentNumberOfTeachers = 0;



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
    string space = " ";
    int year;
    int active;
    int class1, class2, class3, class4;
    string grade1, grade2, grade3, grade4;
}sdb[10];
struct Teachers{
    string fname, lname;
    string space = " ";
    int class1, class2, class3, class4;
}tdb[10];
struct Courses{
    string courses;
}cdb[10];


void studentMenu();
void adminMenu();
void defaultMenu();
void teacherMenu();
void newStudent();
void addDropClass();
void viewClass();
void viewGrades();
void displayStudentStructure();
void approveRejectStudent();
void addRemoveStudent();
void addRemoveTeacher();
void totalClassList();
void assignGrades();
void teachingSchedule();


void displayStudentStructure()
{
    ifstream sdatabaseInFile;

    int testvar = sizeof(sdb)/sizeof(sdb[0]);

    sdatabaseInFile.open("students.txt"); // open students.txt

    if(sdatabaseInFile.fail())
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
    }


        for(int i = 0; i < testvar; i++)
        {
            cout <<
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
            sdb[i].grade4 << endl;
            //cout <<"Student no "<<i<<" loaded"<<endl;
        }
}

//Load Database functions
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
            getline(classesInFile,cdb[i].courses, '\n');
//            classesInFile>>
//            cdb[i].courses;

        }
        cout <<"All classes have been successfully loaded"<<endl;

        classesInFile.close();
    }
}
void sdatabase_load()
{

    ifstream sdatabaseInFile;

    sdatabaseInFile.open("students.txt"); // open students.txt

    if(sdatabaseInFile.fail())
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
        cout << endl <<"All students have been successfully loaded"<<endl << endl;
        sdatabaseInFile.close();
    }
}
void sdatabase_save()
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
            sdb[i].fname<< " " <<
            sdb[i].lname<< " " <<
            sdb[i].year<< " " <<
            sdb[i].active<< " " <<
            sdb[i].class1<< " " <<
            sdb[i].class2<< " " <<
            sdb[i].class3<< " " <<
            sdb[i].class4<< " " <<
            sdb[i].grade1<< " " <<
            sdb[i].grade2<< " " <<
            sdb[i].grade3<< " " <<
            sdb[i].grade4<< endl;
            //cout <<"Student no "<<i<<"saved"<<endl;
        }
        cout <<"All students have been successfully saved"<<endl;
        sdatabaseOutFile.close();
    }
}
void tdatabase_load()
{

    ifstream tdatabaseInFile;

    tdatabaseInFile.open("teachers.txt");


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
void tdatabase_save()
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
            tdb[i].fname<< " " <<
            tdb[i].space<< " " <<
            tdb[i].lname<< " " <<
            tdb[i].class1<< " " <<
            tdb[i].class2<< " " <<
            tdb[i].class3<< " " <<
            tdb[i].class4 << endl;
            //cout <<"Teacher no "<<i<<"saved"<<endl;
            //cout << tdb[i].fname << endl;
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

    sdatabase_load();

    cout << "Enter your first name: ";
    cin >> fname;
    cout << "Enter your last name: ";
    cin >> lname;
    //display the input to user and give user the choice if it is correct or not
    cout << "Your name is " << fname << " " << lname << ".\n"
         << "Is this correct? (y or n): ";
    cin >> response;//user response to yes or no

    //if it is correct then a message display to let user know they can register for classes
    if(tolower(response) == 'y')
    {
        for(int i = 0; i < sizeof(sdb)/sizeof(sdb[0]); i++)
        {
            if (sdb[i].fname == "0")
            {

                if (sdb[i].lname == "0")
                {

                    sdb[i].fname = fname;
                    sdb[i].lname = lname;
                    sdb[i].active = 0;
                    cout << endl << "You were added to the database." << endl;
                    cout << "Now you can register for classes!" << endl << endl;
                    sdatabase_save();
                    studentMenu();
                }
            }
        }

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
            if(tolower(response) == 'y')
            {
                for(int i = 0; i < sizeof(sdb)/sizeof(sdb[0]); i++)
                {
                    if (sdb[i].fname == "0")
                    {

                        if (sdb[i].lname == "0")
                        {

                            sdb[i].fname = fname;
                            sdb[i].lname = lname;
                            sdb[i].active = 0;
                            cout << "You were added to the database." << endl;
                            cout << "Now you can register for classes!" << endl;
                            sdatabase_save();
                            studentMenu();
                        }
                    }
                }

            }
        }
    }
}

//add or drop classes(student)
void addDropClass()
{
    string fname;
    string lname;
    char response;
    char choice = 0;
    int classnumber = 0;
    int counter = 0;
    int minusone = 0;


    cout << "Please Enter your first name: ";
    cin >> fname;
    cout << "Please enter your last name: ";
    cin >> lname;


    //Load Student database and check admin approval
    sdatabase_load();
    //Check admin approval
    int i=0;
    while (i <sizeof(sdb)/sizeof(sdb[0]))
    {
        if (sdb[i].fname == fname)
        {
            if (sdb[i].lname == lname)
            {
                if (sdb[i].active == 0)
                {
                    cout << endl << endl << endl << "*******************************\n*******************************\n*******************************\nYou have not been approved to add classes yet. \nPlease check with an administrator.\n*******************************\n*******************************\n*******************************\n" << endl << endl << endl << endl;
                    studentMenu();
                }
                counter = i;
                cout << endl << "A student matching this name has been found." << endl << endl;
            }
        }
        i++;
    }

    cout << "  Add/Remove Class Menu:\n";
    cout << "  ====================================\n";
    cout << "  1.  Add Class\n";
    cout << "  2.  Remove Class\n";
    cout << "  3.  Back to Main Menu\n";
    cout << "\n";
    cout << "  4.  Exit\n";
    cout << "  ====================================\n";
    cout << "  Enter your selection: ";
    cin >> response;
    cout << endl;


    switch (response)
    {
        case '1':
            //Add Class

                cout << "Please select which slot you would like to add a class to: (1-4)" << endl;
                cin >> choice;

                switch (choice)
                {
                    case '1':
                        //Slot 1
                            totalClassList();
                            cout << "Choose the number of the class you would like to load to slot 1: ";
                            cin >> classnumber;
                            sdb[counter].class1 = classnumber;
                            minusone = classnumber - 1;
                            cout << endl << "You added '" << cdb[minusone].courses << "' to slot 1." << endl << endl;
                            sdatabase_save();
                            studentMenu();

                            break;
                    case '2':
                        //Slot 2
                            totalClassList();
                            cout << "Choose the number of the class you would like to load to slot 2: ";
                            cin >> classnumber;
                            sdb[counter].class2 = classnumber;
                            minusone = classnumber - 1;
                            cout << endl << "You added '" << cdb[minusone].courses << "' to slot 2." << endl << endl;
                            sdatabase_save();
                            studentMenu();

                            break;
                    case '3':
                        //Slot 3
                            totalClassList();
                            cout << "Choose the number of the class you would like to load to slot 3: ";
                            cin >> classnumber;
                            sdb[counter].class3 = classnumber;
                            minusone = classnumber - 1;
                            cout << endl << "You added '" << cdb[minusone].courses << "' to slot 3." << endl << endl;
                            sdatabase_save();
                            studentMenu();

                            break;
                    case '4':
                        //Slot 4
                            totalClassList();
                            cout << "Choose the number of the class you would like to load to slot 4: ";
                            cin >> classnumber;
                            sdb[counter].class4 = classnumber;
                            minusone = classnumber - 1;
                            cout << endl<< "You added '" << cdb[minusone].courses << "' to slot 4." << endl << endl;
                            sdatabase_save();
                            studentMenu();

                            break;

                    default: cout << choice << "is not a valid menu item.\n";
                    cout << endl;
                    studentMenu();
                }

        case '2':
            //Remove Class

        cout << "Please select which slot you would like to remove your class from: (1-4) \n\n If you would like to clear all classes, select 5.";
        cin >> choice;

        switch (choice)
        {
            case '1':
                //Slot 1

                    sdb[counter].class1 = 0;
                    cout << endl<< "Slot 1 has been cleared." << endl<< endl;
                    sdatabase_save();
                    studentMenu();

                    break;
            case '2':
                //Slot 2
                    sdb[counter].class2 = 0;
                    cout << endl<< "Slot 2 has been cleared." << endl<< endl;
                    sdatabase_save();
                    studentMenu();

                    break;
            case '3':
                //Slot 3
                    sdb[counter].class3 = 0;
                    cout << endl<< "Slot 3 has been cleared." << endl<< endl;
                    sdatabase_save();
                    studentMenu();

                    break;
            case '4':
                //Slot 4
                    sdb[counter].class4 = 0;
                    cout << endl<< "Slot 4 has been cleared." << endl<< endl;
                    sdatabase_save();
                    studentMenu();

                    break;

            case '5':
                //Slot 4
                    sdb[counter].class1 = 0;
                    sdb[counter].class2 = 0;
                    sdb[counter].class3 = 0;
                    sdb[counter].class4 = 0;
                    cout << endl << "All slots have been cleared." << endl << endl;
                    sdatabase_save();
                    studentMenu();

                    break;

            default: cout << choice << "is not a valid menu item.\n";
            cout << endl;
            studentMenu();
        }

        case '3':
            defaultMenu();
            break;

        case '4':
        cout << "Goodbye.\n";
        exit(0); //Exit Program
        break;

        default: cout << response << "is not a valid menu item.\n";
        cout << endl;
    }
}

//**admin**Approve students to add classes
void approveRejectStudent()
{
    string fname;
    string lname;
    char response;


    cout << "Please Enter your first name: ";
    cin >> fname;
    cout << "Please enter your last name: ";
    cin >> lname;


    //Load Student database and check admin approval

    sdatabase_load();


    //Check admin approval
    int i=0;
    while (i <sizeof(sdb)/sizeof(sdb[0]))
    {
        if (sdb[i].fname == fname)
        {
            if (sdb[i].lname == lname)
            {
                if (sdb[i].active == 0)
                {
                    cout << endl << "This student is currently awaiting approval. " << endl << endl;
                }
                else if (sdb[i].active == 1)
                {
                    cout << endl << "This student has already been approved. " << endl << endl;
                    adminMenu();
                }
                else
                {
                    cout << endl << "An error occured. Please check the database file." << endl << endl;
                    adminMenu();
                }

                cout << endl << "Do you want to approve student to add classes? (y or n) " ;
                cin >> response;

                switch (response)
                {
                    case 'y':
                        //approve student
                        sdb[i].active = 1;
                        sdatabase_save();
                        adminMenu();
                        break;

                    case 'n':
                        //reject student
                        sdb[i].active = 0;
                        sdatabase_save();
                        adminMenu();
                        break;

                    default: cout << endl << response << "is not a valid menu item.\n" << endl;
                    cout << endl;
                }

            }
        }
        i++;
    }


}

//**admin**Add/Remove Students
void addRemoveStudent()
{
    string fname;
    string lname;
    char response;


    cout << "Please Enter the student's first name: " << endl;
    cin >> fname;
    cout << "Please Enter the student's last name: " << endl;
    cin >> lname;


    //Load Student database
    sdatabase_load();

    //Check to see if student exists
    for(int i = 0; i < sizeof(sdb)/sizeof(sdb[0]); i++)
    {
        if (sdb[i].fname == fname)
        {

            if (sdb[i].lname == lname)
            {

                cout << endl << "A student matching this name has been found." << endl << endl;
            }
        }
    }

    cout << "  Add/Remove Student Menu:\n";
    cout << "  ====================================\n";
    cout << "  1.  Add Student\n";
    cout << "  2.  Remove Student\n";
    cout << "  3.  Back to Main Menu\n";
    cout << "\n";
    cout << "  4.  Exit\n";
    cout << "  ====================================\n";
    cout << "  Enter your selection: ";
    cin >> response;
    cout << endl;

    switch (response)
    {
        case '1':
            //Add student
            for(int i = 0; i < sizeof(sdb)/sizeof(sdb[0]); i++)
            {
                if (sdb[i].fname == "0")
                {

                    if (sdb[i].lname == "0")
                    {

                        sdb[i].fname = fname;
                        sdb[i].lname = lname;
                        cout << endl << fname << " " << lname << " was added to the database." << endl << endl;
                        sdatabase_save();
                        adminMenu();
                    }
                }
            }
            break;

        case '2':
            //Remove Student
        for(int i = 0; i < sizeof(sdb)/sizeof(sdb[0]); i++)
        {
            if (sdb[i].fname == fname)
            {

                if (sdb[i].lname == lname)
                {

                    sdb[i].fname = "0";
                    sdb[i].lname = "0";
                    sdb[i].year = 0;
                    sdb[i].active = 0;
                    sdb[i].class1 = 0;
                    sdb[i].class2 = 0;
                    sdb[i].class3 = 0;
                    sdb[i].class4 = 0;
                    sdb[i].grade1 = "0";
                    sdb[i].grade2 = "0";
                    sdb[i].grade3 = "0";
                    sdb[i].grade4 = "0";
                    cout << endl << fname << " " << lname << " was removed from the system." << endl << endl;
                    sdatabase_save();
                    adminMenu();
                }
            }
        }
            break;

        case '3':
            defaultMenu();
            break;

        case '4':
        cout << endl << "Goodbye.\n";
        exit(0); //Exit Program
        break;

        default: cout << response << "is not a valid menu item.\n";
        cout << endl;
    }
}

//**admin**Add/Remove Teachers
void addRemoveTeacher()
{
    string fname;
    string lname;
    char response;


    cout << "Please Enter the Teacher's first name: " << endl;
    cin >> fname;
    cout << "Please Enter the Teacher's last name: " << endl;
    cin >> lname;


    //Load Teacher database
    tdatabase_load();

    //Check to see if Teacher exists
    for(int i = 0; i < sizeof(tdb)/sizeof(tdb[0]); i++)
    {
        if (tdb[i].fname == fname)
        {

            if (tdb[i].lname == lname)
            {

                cout << endl << "A Teacher matching this name has been found." << endl << endl;
            }
        }
    }

    cout << "  Add/Remove Teacher Menu:\n";
    cout << "  ====================================\n";
    cout << "  1.  Add Teacher\n";
    cout << "  2.  Remove Teacher\n";
    cout << "  3.  Back to Main Menu\n";
    cout << "\n";
    cout << "  4.  Exit\n";
    cout << "  ====================================\n";
    cout << "  Enter your selection: ";
    cin >> response;
    cout << endl;

    switch (response)
    {
        case '1':
            //Add Teacher
            for(int i = 0; i < sizeof(tdb)/sizeof(tdb[0]); i++)
            {
                if (tdb[i].fname == "0")
                {

                    if (tdb[i].lname == "0")
                    {

                        tdb[i].fname = fname;
                        tdb[i].lname = lname;
                        cout << endl << fname << " " << lname << " was added to the database." << endl << endl;
                        tdatabase_save();
                        adminMenu();
                    }
                }
            }
            break;

        case '2':
            //Remove Teacher
        for(int i = 0; i < sizeof(tdb)/sizeof(tdb[0]); i++)
        {
            if (sdb[i].fname == fname)
            {

                if (sdb[i].lname == lname)
                {

                    tdb[i].fname = "0";
                    tdb[i].lname = "0";
                    tdb[i].class1 = 0;
                    tdb[i].class2 = 0;
                    tdb[i].class3 = 0;
                    tdb[i].class4 = 0;

                    cout << endl << fname << " " << lname << " was removed from the system." << endl << endl;
                    tdatabase_save();
                    adminMenu();
                }
            }
        }
            break;

        case '3':
            defaultMenu();
            break;

        case '4':
        cout << "Goodbye.\n";
        exit(0); //Exit Program
        break;

        default: cout << response << "is not a valid menu item.\n";
        cout << endl;
    }
}


//Total class List
void totalClassList()
{
    classes_load();
    for(int i = 0; i < sizeof(cdb)/sizeof(cdb[0]); i++)
    {
        cout << cdb[i].courses << endl;

    }
    cout << endl;
}

//view class schedule
void viewClass()
{
    //after all the add or drop classes the class schedule will display
    string fname;
    string lname;

    cout << "Please Enter the Student's first name: ";
    cin >> fname;
    cout << "Please enter the Student's last name: ";
    cin >> lname;


    //Load Student database and check admin approval
    sdatabase_load();
    //Check admin approval
    int i=0;
    while (i <sizeof(sdb)/sizeof(sdb[0]))
    {
        if (sdb[i].fname == fname)
        {
            if (sdb[i].lname == lname)
            {
                totalClassList();
                cout << endl << "Your classes are: "
                     << sdb[i].class1 << " "
                     << sdb[i].class2 << " "
                     << sdb[i].class3 << " "
                     << sdb[i].class4 << endl << endl;
            }
        }
        i++;
    }
}

void assignGrades()
{
    string fname;
    string lname;
    char choice;

    cout << "Please enter the student's first name: ";
    cin >> fname;
    cout << "Please enter the student's last name: ";
    cin >> lname;


    //Load Student database
    sdatabase_load();

    int i=0;
    while (i <sizeof(sdb)/sizeof(sdb[0]))
    {
        if (sdb[i].fname == fname)
        {
            if (sdb[i].lname == lname)
            {
                cout << endl << "This student's courses are: "
                     << sdb[i].class1 << " "
                     << sdb[i].class2 << " "
                     << sdb[i].class3 << " "
                     << sdb[i].class4 << endl << endl;

                cout << "Pick the slot you need to enter the grade for: (1-4)";
                        cin >> choice;
                        switch (choice)
                        {
                        case '1':
                            //Slot 1

                                cout << endl << "Enter the Grade: ";
                                cin >> sdb[i].grade1;
                                sdatabase_save();
                                studentMenu();

                                break;
                        case '2':
                            //Slot 2
                                cout << endl << "Enter the Grade: ";
                                cin >> sdb[i].grade2;
                                sdatabase_save();
                                studentMenu();

                                break;
                        case '3':
                            //Slot 3
                                cout << endl << "Enter the Grade: ";
                                cin >> sdb[i].grade3;
                                sdatabase_save();
                                studentMenu();

                                break;
                        case '4':
                            //Slot 4
                                cout << endl << "Enter the Grade: ";
                                cin >> sdb[i].grade4;
                                sdatabase_save();
                                studentMenu();

                                break;

                        default: cout << choice << "is not a valid menu item.\n";
                        cout << endl;
                        teacherMenu();
                        }
            }
        }
        i++;
    }
}

void teachingSchedule()
{
    string fname;
    string lname;
    char response;


    cout << "Please Enter the Teacher's first name: ";
    cin >> fname;
    cout << "Please Enter the Teacher's last name: ";
    cin >> lname;


    //Load Teacher database
    tdatabase_load();

    //Check to see if Teacher exists
    for(int i = 0; i < sizeof(tdb)/sizeof(tdb[0]); i++)
        {
            if (tdb[i].fname == fname)
            {

                if (tdb[i].lname == lname)
                {
                    totalClassList();
                    cout << endl << "You are Teaching: "
                         << tdb[i].class1 << " "
                         << tdb[i].class2 << " "
                         << tdb[i].class3 << " "
                         << tdb[i].class4 << endl << endl;
                }
            }
        }


}

//view grades
void viewGrades()
{
    //the grades will be display with the file upload by the teacher
    string fname;
    string lname;

    cout << "Please Enter your first name: ";
    cin >> fname;
    cout << "Please enter your last name: ";
    cin >> lname;


    //Load Student database
    sdatabase_load();

    int i=0;
    while (i <sizeof(sdb)/sizeof(sdb[0]))
    {
        if (sdb[i].fname == fname)
        {
            if (sdb[i].lname == lname)
            {
                cout << endl << "Your grades are: "
                     << sdb[i].grade1 << " "
                     << sdb[i].grade2 << " "
                     << sdb[i].grade3 << " "
                     << sdb[i].grade4 << endl << endl;
            }
        }
        i++;
    }
}
void teacherMenu()
{
    {
        char selection;

           do
           {//menu
               cout << "  Teacher Menu - Choose your role:\n";
               cout << "  ====================================\n";
               cout << "  1.  View Teaching Schedule\n";
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
                       //View Teaching Schedule
                       teachingSchedule();
                       break;

                   case '2':
                       //View Student Schedule
                       viewClass();
                       break;
                   case '3':
                       //Assign Grades
                       assignGrades();
                       break;
                   case '4':
                       defaultMenu();
                       break;
                   case '5':
                       cout << "Goodbye.\n";
                       exit(0); //Exit Program
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
                       newStudent();
                       break;

                   case '2':
                       //Add/Remove Classes
                       addDropClass();
                       break;
                   case '3':
                       //View Class Schedule
                       viewClass();

                       break;
                   case '4':
                       //View Grades
                       viewGrades();
                       break;
                   case '5':
                       defaultMenu();
                       break;
                   case '6':
                       cout << "Goodbye.\n";
                       exit(0); //Exit Program
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
                       addRemoveStudent();
                       break;

                   case '2':
                       //Add/Remove Teachers
                       addRemoveTeacher();
                       break;
                   case '3':
                       //Approve/Reject Students
                       approveRejectStudent();
                       break;
                   case '4':
                       defaultMenu();
                       break;
                   case '5':
                       cout << "Goodbye.\n";
                       exit(0); //Exit Program
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
               cout << "  1.  Student\n";
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
                       exit(0); //Exit Program
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
    //displayStudentStructure();
    getdbSize();

    sdatabase_load();

    tdatabase_load();
    classes_load();
    //tdatabase_save();
    //Test print the database after initialization
    /*
    for(int j = 0; j < 5; j++)
        {
        cout<<sdatabase[j].fname<<sdatabase[j].lname;
        cout<<tdatabase[j].fname<<tdatabase[j].lname;
        }
    */
   defaultMenu();
}
