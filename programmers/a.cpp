#include <string>
#include <vector>
#include <deque>

using namespace std;

int roate(vector<vector<int>> &matrix, int x1, int y1, int x2, int y2)
{
    int current_x = x1;
    int current_y = y1;
    deque<int> num_list;
    while (current_x <= x2 && current_y < y2)
    {
        int num = matrix[current_x][current_y];
        num_list.push_back(num);
        if (current_x < x2)
        {
            current_x++;
        }
        else if (current_y < y2)
        {
            current_y++;
        }
    }
    while (current_x >= x1 && current_y > y1)
    {
        int num = matrix[current_x][current_y];
        num_list.push_back(num);
        if (current_x > x1)
        {
            current_x--;
        }
        else if (current_y > y1)
        {
            current_y--;
        }
    }

    current_x = x1;
    current_y = y1;

    int last = num_list.back();
    num_list.pop_back();
    num_list.push_front(last);

    int i = 0;
    while (current_x <= x2 && current_y < y2)
    {
        matrix[current_x][current_y] = num_list[i];
        i++;
        if (current_x < x2)
        {
            current_x++;
        }
        else if (current_y < y2)
        {
            current_y++;
        }
    }
    while (current_x >= x1 && current_y > y1)
    {
        matrix[current_x][current_y] = num_list[i];
        i++;
        if (current_x > x1)
        {
            current_x--;
        }
        else if (current_y > y1)
        {
            current_y--;
        }
    }
    return *min(num_list.begin(), num_list.end());
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{

    vector<vector<int>> matrix(rows + 1, vector<int>(columns + 1));
    int num = 1;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            matrix[i][j] = num;
            num++;
        }
    }
    vector<int> answer;
    for (int i = 0; i < queries.size(); i++)
    {
        vector<int> query = queries[i];
        int x1 = query[0];
        int y1 = query[1];
        int x2 = query[2];
        int y2 = query[3];
        answer.push_back(roate(matrix, x1, y1, x2, y2));
    }
    return answer;
}