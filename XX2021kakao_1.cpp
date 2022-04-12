/*
���� : 
�÷��̾�� �׸��� ���� ���� �� �ֽ��ϴ�.


�÷��̾�� ������ 4 ���� �� �� �ϳ��� �̵��� �� ������ ������ �������� ���� ���ѵ˴ϴ�.

�� ��ġ���� �ٸ� ��ġ�� �̵��ϴ� ���� ����� �߻��Ѵ�.

i ��� i + 1 �� ���̸� �̵��ϴ� ����� costRows [i]�̰�
j ���� j + 1 �� ���̸� �̵��ϴ� ����� costCols [j]�Դϴ�.

�׸��� ������ ���� �������� �� �������� �̵��ϴ� �� �ʿ��� �ּ� ����� ã���ϴ�.

rows : ��
cols : ��
initR : ���� row
initC : ���� col
finalR :�� row
finalC :�� col
costRows ���
costCols ���
*/

//���� ��� �°� ��� Ʋ��

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

int dr[] = { -1, 0, 1, 0 }; //�������
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
            continue; //�پ�Ѵ´�.
        }
        else if (cost >= hap) {
            q.pop();
            continue; //�پ�Ѵ´�.
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nR = hR + dr[i];
            int nC = hC + dc[i];
            if (nR < rows && nR >= 0 && nC < cols && nC >= 0) {
                if ((hR - 1 == nR) && (hC == nC)) { //�� ���� ���� ����� �������� 
                    q.push({ {nR,nC},cost });
                }
                else if ((hR == nR) && (hC + 1 == nC)) {
                    q.push({ {nR,nC},cost + costCols[hC] });
                }
                else if ((hR + 1 == nR) && (hC == nC)) {
                    q.push({ {nR,nC},cost + costRows[hR] });
                }
                else if ((hR == nR) && (hC - 1 == nC)) { //�·� ���º�� ��������
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

