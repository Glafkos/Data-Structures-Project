#include <iostream>
#include <vector>

using namespace std;

vector <int> merge (vector<int> left, vector<int> right,int &counter)
{
   vector<int> result;

   while ((int)left.size() > 0 || (int)right.size() > 0)
    {

      if ((int)left.size() > 0 && (int)right.size() > 0)
        {
         if ((int)left.front() <= (int)right.front())
         {
            counter++;
            result.push_back((int)left.front());
            left.erase(left.begin());
         }
         else
         {
            counter++;
            result.push_back((int)right.front());
            right.erase(right.begin());
         }
        }
       else if ((int)left.size() > 0)
        {
            for (int i = 0; i < (int)left.size(); i++)
               result.push_back(left[i]);
            break;
        }
        else if ((int)right.size() > 0)
            {
                for (int i = 0; i < (int)right.size(); i++)
                    result.push_back(right[i]);
                break;
            }
   }
   return result;
}

vector<int> mergeSort(vector<int> table,int &counter)
{
    if (table.size() <= 1)
        return table;

    vector<int> left, right, result;

    int middle = ((int)table.size()+ 1) / 2;

    for (int i = 0; i < middle; i++)
    {
      left.push_back(table[i]);
    }

    for (int i = middle; i < (int)table.size(); i++)
    {
      right.push_back(table[i]);
    }

    left = mergeSort(left,counter);
    right = mergeSort(right,counter);
    result = merge(left, right,counter);

   return result;
}
