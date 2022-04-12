/*
문제 : 
플레이어는 그리드 내의 셀에 서 있습니다.


플레이어는 인접한 4 개의 셀 중 하나로 이동할 수 있지만 동작은 레이저에 의해 제한됩니다.

한 위치에서 다른 위치로 이동하는 데는 비용이 발생한다.

i 행과 i + 1 행 사이를 이동하는 비용은 costRows [i]이고
j 열과 j + 1 열 사이를 이동하는 비용은 costCols [j]입니다.

그리드 내에서 시작 지점에서 끝 지점으로 이동하는 데 필요한 최소 비용을 찾습니다.

rows : 행
cols : 열
initR : 시작 row
initC : 시작 col
finalR :끝 row
finalC :끝 col
costRows 비용
costCols 비용
*/

//테케 몇개는 맞고 몇개는 틀림

#include <iostream>
#include <queue>
#include <fstream>
#include <istream>
#include <string>


using namespace std;

string ltrim(const string&);
string rtrim(const string&);



/*
 * Complete the 'minCost' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER rows
 *  2. INTEGER cols
 *  3. INTEGER initR
 *  4. INTEGER initC
 *  5. INTEGER finalR
 *  6. INTEGER finalC
 *  7. INTEGER_ARRAY costRows
 *  8. INTEGER_ARRAY costCols
 */

int dr[] = { -1, 0, 1, 0 }; //상우하좌
int dc[] = { 0, 1, 0, -1 };
int MIN = 987654321;

int minCost(int rows, int cols, int initR, int initC, int finalR, int finalC, vector<int> costRows, vector<int> costCols) {
    int hap = 0;
    for (int i = 0; i < rows; i++) {
        hap += costRows[i];
    }
    for (int i = 0; i < cols; i++) {
        hap += costCols[i];
    }
    queue <pair<pair<int, int>, int>> q;
    q.push({ {initR,initC},0 });
    while (!q.empty()) {
        int hR = q.front().first.first;
        int hC = q.front().first.second;
        int cost = q.front().second;
        if (hR == finalR && hC == finalC) {
            if (cost <= MIN) {
                MIN = cost;
            }
            q.pop();
            continue; //뛰어넘는다.
        }
        else if (cost >= hap) {
            q.pop();
            continue; //뛰어넘는다.
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nR = hR + dr[i];
            int nC = hC + dc[i];
            if (nR < rows && nR >= 0 && nC < cols && nC >= 0) {
                if ((hR - 1 == nR) && (hC == nC)) { //상 으로 가는 비용은 들지않음 
                    q.push({ {nR,nC},cost });
                }
                else if ((hR == nR) && (hC + 1 == nC)) {
                    q.push({ {nR,nC},cost + costCols[hC] });
                }
                else if ((hR + 1 == nR) && (hC == nC)) {
                    q.push({ {nR,nC},cost + costRows[hR] });
                }
                else if ((hR == nR) && (hC - 1 == nC)) { //좌로 가는비용 들지않음
                    q.push({ {nR,nC},cost });
                }
            }
        }
    }
    return MIN;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rows_temp;
    getline(cin, rows_temp);

    int rows = stoi(ltrim(rtrim(rows_temp)));

    string cols_temp;
    getline(cin, cols_temp);

    int cols = stoi(ltrim(rtrim(cols_temp)));

    string initR_temp;
    getline(cin, initR_temp);

    int initR = stoi(ltrim(rtrim(initR_temp)));

    string initC_temp;
    getline(cin, initC_temp);

    int initC = stoi(ltrim(rtrim(initC_temp)));

    string finalR_temp;
    getline(cin, finalR_temp);

    int finalR = stoi(ltrim(rtrim(finalR_temp)));

    string finalC_temp;
    getline(cin, finalC_temp);

    int finalC = stoi(ltrim(rtrim(finalC_temp)));

    string costRows_count_temp;
    getline(cin, costRows_count_temp);

    int costRows_count = stoi(ltrim(rtrim(costRows_count_temp)));

    vector<int> costRows(costRows_count);

    for (int i = 0; i < costRows_count; i++) {
        string costRows_item_temp;
        getline(cin, costRows_item_temp);

        int costRows_item = stoi(ltrim(rtrim(costRows_item_temp)));

        costRows[i] = costRows_item;
    }

    string costCols_count_temp;
    getline(cin, costCols_count_temp);

    int costCols_count = stoi(ltrim(rtrim(costCols_count_temp)));

    vector<int> costCols(costCols_count);

    for (int i = 0; i < costCols_count; i++) {
        string costCols_item_temp;
        getline(cin, costCols_item_temp);

        int costCols_item = stoi(ltrim(rtrim(costCols_item_temp)));

        costCols[i] = costCols_item;
    }

    int result = minCost(rows, cols, initR, initC, finalR, finalC, costRows, costCols);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

