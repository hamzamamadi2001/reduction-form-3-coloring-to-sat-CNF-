// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int main()

{
    
    std::cout << "What is the dimensions of the array (the total number of node exist)\n";

    int num;
     std::cin >> num;
  std::cout << "enter now the contents";
  int** graphe = new int* [num];
  for (size_t i = 0; i < num; i++)
  {
      graphe[i] = new int[num];
  }
  for (size_t i = 0; i < num; i++)
      for (size_t j = 0; j < num; j++)
      {
          std::cin >> graphe[i][j];
      }
 

   std::string fname;
  std::cout << "enter the name of the DIMACS file in order to create it \n";
  std::cin >> fname;


  std::ofstream MyFile(fname+".cnf");
  


  for (size_t i = 0; i < num; i++) {
for (size_t j = 0; j < num; j++)
      {
    std::cout << " ";
          std::cout << graphe[i][j];
      }
std::cout << "\n";
  }
      
  int ones_count = 0;

  for (size_t i = 0; i < num; i++)
  {
      for (size_t j = i+1; j < num;j++)
      {
          if (graphe[i][j] == 1) {
              ones_count++;
          }
      }

  }
  int total_number_of_clauses = ones_count * 3 + num * 4;
  
      int** formula = new int* [total_number_of_clauses];
      int j = 0;
      int i = 0;
  for (i; j < num; i=i+3+1,j++)
  {
      formula[i] = new int[3];
      formula[i+1] = new int[2];
      formula[i+2] = new int[2];
      formula[i+3] = new int[2];
      //***********************
      formula[i][0] = j * 3 + 1;
      formula[i][1] = j * 3 + 2;
      formula[i][2] = j * 3 + 3;
      //***********************
      formula[i+1][0] = -(j * 3 + 1);
      formula[i + 1][1] =-(j * 3 + 2);
      //***************************
      formula[i + 2][0] = -(j * 3 + 1);
      formula[i + 2][1] = -(j * 3 + 3);
      //****************************
      formula[i + 3][0] = -(j * 3 + 2);
      formula[i + 3][1] = -(j * 3 + 3);
  }
  int last_index = i;
  int last_index_for_loop = last_index;
 


  for (int i = 0; i < num; i++)
  {
      for (int  j=i+1 ; j < num; j++)
      {
          if (graphe[i][j] == 1)
          {
              formula[last_index] = new int[2];
              formula[last_index+1] = new int[2];
              formula[last_index+2] = new int[2];
              //***********************
              formula[last_index][0] = -(i * 3 + 1);
              formula[last_index][1] = -(j * 3 + 1);
              //*********************
              formula[last_index + 1][0] = -(i * 3 + 2);
              formula[last_index + 1][1] = -(j * 3 + 2);
               //*******************
              formula[last_index + 2][0] = -(i * 3 + 3);
              formula[last_index + 2][1] = -(j * 3 + 3);
              last_index = last_index + 3;


          }

      }

  }

  MyFile << "p cnf ";
  MyFile << num*3;
  MyFile << " ";
  MyFile << total_number_of_clauses;

  MyFile << std::endl;
   int k;
  for (int i = 0; i < num * 4; i++)

  {
      k = 2;
      if (i == 0 || i % 4 == 0) {
          k = 3;
  }

      
      for (size_t j = 0; j < k ; j++)
      {
          MyFile << formula[i][j];
          MyFile << " ";
        if(j+1>=k)
        MyFile << "0";
      }
      MyFile << std::endl;

     

  }

  for (last_index_for_loop; last_index_for_loop< total_number_of_clauses; last_index_for_loop++)

  {
     

      
      for (size_t j = 0; j < 2; j++)
      {
          MyFile << formula[last_index_for_loop][j];
          MyFile << " ";
          if(j+1>=2)
          MyFile << "0";
      }
      MyFile<< std::endl;
     

  }
  MyFile.close(); 





}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
