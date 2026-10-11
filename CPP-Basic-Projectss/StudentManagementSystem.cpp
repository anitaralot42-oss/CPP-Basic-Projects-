#include <iostream>
using namespace std;

class student
{
public:
   int id;
   string name;
   int age;

   bool login()
   { // bool true and false me answer show krega
      string user, pass;
      cout << "enter user name : ";
      cin >> user;
      cout << "enter password :";
      cin >> pass;
      if (user == "student" && pass == "2621")
      {
         cout << "----login successfully!!---- \n";
         return true;
      }
      else
      {
         cout << "invalid password \n";
         return false;
      }
   }

   void add_student(student s[], int count)
   {
      cout << "enter student id : " << endl;
      cin >> s[count].id;
      cout << "enter student name :" << endl;
      cin >> s[count].name;
      cout << "enter student age :" << endl;
      cin >> s[count].age;
   }

   void search(student s[], int count)
   {
      if (count == 0)
      {
         cout << "no student search :";
      }

      string searchname;
      cout << "enter search name: " << endl;
      cin.ignore();
      getline(cin, searchname);
      for (int i = 0; i < count; i++)
      {

         if (s[i].name == searchname)
         {
            cout << "student found \n";
            cout << "ID   : " << s[i].id << endl;
            cout << "NAME : " << s[i].name << endl;
            cout << "AGE  : " << s[i].age << endl;
            return;
         }
      }
      cout << "no student found..\n";
   }

   void update_student(student s[], int count)
   {
      if (count == 0)
      {
         cout << "---no student update --";
         return;
      }

      string updatename;
      cout << "enter name : " << endl;
      cin.ignore();
      getline(cin, updatename);

      for (int i = 0; i < count; i++)
      {
         if (s[i].name == updatename)
         {
            cout << "update name :\n";
            cin >> s[i].name;
            cout << "update id :\n";
            cin >> s[i].id;
            cout << "update age :\n";
            cin >> s[i].age;

            cout << "update student succesfully !!";
            return;
         }
      }
   }

   void delete_student(student s[], int &count)
   {
      if (count == 0)
      {
         cout << "---no student delete --";
         return;
      }

      string deletename;
      cout << "enter student name delete: " << endl;
      cin.ignore();
      getline(cin, deletename);

      for (int i = 0; i < count; i++)
      {
         if (s[i].name == deletename)
         {
            for (int j = i; j < count - 1; j++)
            {
               s[j] = s[j + 1];
            }
            count--;
            cout << "delete student successfully !!\n";
            return;
         }
      }

      cout << "no student ";
   }

   void display(student s[], int total)
   { // all student ko show krne ke liye loop use

      for (int j = 0; j < total; j++)
      {
         cout << "ID   : " << s[j].id << endl;
         cout << "NAME : " << s[j].name << endl;
         cout << "AGE  : " << s[j].age << endl;
      }
      if (total == 0)
      {
         cout << "no student \n";
      }
   }
};

int main()
{
   class student s[100];
   class student s1;
   int choice;
   int count = 0; // count ko intilazation krna pdegaa varana index pr garbage value aayegi
   if (!s1.login())
   {
      return 0;
   }

   do
   {
      cout << "--- enter your choice----" << endl;
      cout << "1. student_add\n"
           << "2.student_display\n"
           << "3.search_student\n"
           << "4.updatename\n"
           << "5.deletename\n"
           << "6.exit\n";
      cin >> choice;
      switch (choice)
      {
      case 1:
         s1.add_student(s, count);
         count++;
         break;
      case 2:
         s1.display(s, count);
         break;

      case 3:
         s1.search(s, count);
         break;
      case 4:
         s1.update_student(s, count);
         break;
      case 5:
         s1.delete_student(s, count);
         break;

      default:
         cout << "---invalid choice ---";
      }
   } while (choice != 6);
}
