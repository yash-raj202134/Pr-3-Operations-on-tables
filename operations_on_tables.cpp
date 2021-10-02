/* A program to perform following operations on tables using functions only 
Addition ,Subtraction, Multiplication & Transpose*/
#include <iostream>
using namespace std;
#define ROW 2
#define COLUMN 2
class Table
{
public:                            //Data Members to store the results of various operations.
    int add[ROW][COLUMN];
    int subtract[ROW][COLUMN];
    int sumproduct;                  
    int multiply[ROW][COLUMN];
    int transpose[ROW][COLUMN];
    void input(int table[ROW][COLUMN])     //A function to input table from user.
    {
        cout << "[" << ROW << "]"
             << "[" << COLUMN << "] : \n";
        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COLUMN; j++)
            {
                cout << "Enter element (" << i << "," << j << ") >> ";
                cin >> table[i][j];
            }
    }
    void display(int table[ROW][COLUMN])     //A function to display the table contents on output screen.
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COLUMN; j++)
                cout << " " << table[i][j] << " ";
            cout << endl;
        }
    }
};

class Addition : public Table
{
public:
    void addTable(int x[ROW][COLUMN], int y[ROW][COLUMN])     //A function to perform Addition operation.
    {
        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COLUMN; j++)
                add[i][j] = x[i][j] + y[i][j];
        Table t;
        t.display(add);     //Display the result.
    }
};

class Subtraction : public Table
{
public:
    void subtractTable(int x[ROW][COLUMN], int y[ROW][COLUMN])     //A function to perform subtraction operation.
    {
        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COLUMN; j++)
                subtract[i][j] = x[i][j] - y[i][j];
        Table t;
        t.display(subtract);
    }
};

class Multiplication : public Table
{
public:                                                           //A function to perform multiplication operation.
    int multiplyTable(int m1[ROW][COLUMN], int row1, int column1, int m2[ROW][COLUMN], int row2, int column2)
    {
        sumproduct = 0;
        int val[row1][column2];

        if (column1 != row2)
        {
            cout << "Multiplication not possible !!";
            return -1;
        }
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < column2; j++)
            {
                for (int k = 0; k < column1; k++)
                    sumproduct += m1[i][k] * m2[k][j];
                val[i][j] = sumproduct;
                sumproduct = 0;
                multiply[i][j] = val[i][j];
            }
        }
        Table o;
        o.display(multiply);
        return 0;
    }
};

class Transpose : public Table
{
public:
    void TransposeTable(int m[ROW][COLUMN])       //A function to get transpose of a table.
    {
        for (int i = 0; i < ROW; i++)
            for (int j = 0; j < COLUMN; j++)
                transpose[i][j] = m[j][i];
        Table op;
        op.display(transpose);
    }
};
int main(void)
{
    int table1[ROW][COLUMN], table2[ROW][COLUMN];        //two tables for operations.
    Table tb;

    cout << "Enter table 1 ";
    tb.input(table1);
    cout << "Enter table 2 ";
    tb.input(table2);
    cout << endl;
    Addition a;
    cout << "Addition of table 1 and table 2 \n";
    a.addTable(table1, table2); //Addition.
    cout << endl;
    Subtraction b;
    cout << "Subtraction of table 1 and table 2 \n";
    b.subtractTable(table1, table2); //Subtraction.
    cout << endl;
    Multiplication c;
    cout << "Multiplication of table 1 and table 2 \n";
    c.multiplyTable(table1, ROW, COLUMN, table2, ROW, COLUMN); //Multiplication.
    cout << endl;
    cout << "Transpose of table 1 and table 2 \n";
    Transpose d;
    d.TransposeTable(table1); //Transpose.
    cout << endl;
    d.TransposeTable(table2);
    return 0;
}
