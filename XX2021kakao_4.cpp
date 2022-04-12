/*
���� ȸ�簡 Ư�� ���ÿ� �ֽ��ϴ�.

�׵��� ��ǰ�� ����� ���η� ����� �ٸ� ���÷� ��۵Ǿ��������

�Ϻ� ���ô� �бⰡ ������� �ʾ� ������ �Ұ����� �� �ֽ��ϴ�.

��� ������ ���� �Ÿ��� ���� ������ ���� �켱 ������ ���� �����˴ϴ�.

������ ��, ���θ� ���� ���� �� ���� ȸ�簡 ��ġ�� ���ø� ����Ͽ� ��ǰ�� ��� �� ������ ������ �����մϴ�.

// �׷����� �����ϰ� ���� ��������, ���������� �� ȸ�縦 ������ָ� �ȴ�.
*/






/*
 * Complete the 'order' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. UNWEIGHTED_INTEGER_GRAPH city
 *  2. INTEGER company
 */

 /*
  * For the unweighted graph, <name>:
  *
  * 1. The number of nodes is <name>_nodes.
  * 2. The number of edges is <name>_edges.
  * 3. An edge exists between <name>_from[i] and <name>_to[i].
  *
  */

//���� ��Ʋ��


/*
int visit[10001] = { 0, };
vector <int> fin;

vector<int> order(int city_nodes, vector<int> city_from, vector<int> city_to, int company) {
    priority_queue <pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq; //pq ����
    int cnt = -1;
    int newcp = company;
    for (int i = 0; i < city_from.size(); i++) {
        if (city_from[i] == 1) {
            pq.push({ {city_from[i],city_to[i]},cnt + 1 });
        }
    }
    newcp++;
    cnt++;
    while (!pq.empty()) { //�������� 
        int hcompany = newcp; //������ ȸ��
        for (int i = 0; i < city_from.size(); i++) {
            if (city_from[i] == hcompany) {
                pq.push({ {city_from[i],city_to[i]},cnt + 1 });
            }
        }
        pair<pair<int, int>, int> temp = pq.top();
        pq.pop();
        int from = temp.first.first;
        int to = temp.first.second;
        int count = temp.second;
        cnt = count + 1; //����ͺ��� 1 ũ�� ���ߵȴ�.
        company = to; //ȸ�� �缳��
        if (!visit[newcp]) {
            visit[newcp] = 1;
            fin.push_back(newcp);
        }
        pq.pop(); //�� ���� �̾��ش�.
    }
    for (int i = 0; i < fin.size(); i++) {
        printf("%d", fin[i]);
    }
    return fin;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string city_nodes_edges_temp;
    getline(cin, city_nodes_edges_temp);

    vector<string> city_nodes_edges = split(rtrim(city_nodes_edges_temp));

    int city_nodes = stoi(city_nodes_edges[0]);
    int city_edges = stoi(city_nodes_edges[1]);

    vector<int> city_from(city_edges);
    vector<int> city_to(city_edges);

    for (int i = 0; i < city_edges; i++) {
        string city_from_to_temp;
        getline(cin, city_from_to_temp);

        vector<string> city_from_to = split(rtrim(city_from_to_temp));

        int city_from_temp = stoi(city_from_to[0]);
        int city_to_temp = stoi(city_from_to[1]);

        city_from[i] = city_from_temp;
        city_to[i] = city_to_temp;
    }

    string company_temp;
    getline(cin, company_temp);

    int company = stoi(ltrim(rtrim(company_temp)));

    vector<int> result = order(city_nodes, city_from, city_to, company);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

vector<string> split(const string& str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

*/

#include <iostream>
#include <queue>
#include <fstream>
#include <istream>
#include <string>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);
vector<string> split(const string&);

int visit[10001] = { 0, };
vector <int> fin;


// pq�� ����� �۵��ϴ����� Ȯ���غ���

vector<int> order(int city_nodes, vector<int> city_from, vector<int> city_to, int company) {
    queue < pair<pair<int, int>, int>> q; //q ����
    priority_queue < pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq; // �ڵ� ������ ���� pq ����
    //priority_queue < pair<pair<int, int>, int>> pq; //

    int cnt = 0;
    for (int i = 0; i < city_from.size(); i++) {
        if (city_from[i] == company) {
            pq.push({ {city_from[i],city_to[i]},cnt }); //pq�� �����Ƿ� �����鼭 �ڵ� ����
        }
        //������ city_from ���� ���ְԵȴٸ�?
    }
    int s = pq.size();
    for (int i = 0; i < s; i++) {
        pair<pair<int, int>, int> temp = pq.top();
        pq.pop();
        int from = temp.first.first;
        int to = temp.first.second;
        int count = temp.second;
        q.push({ {from,to},count }); //���ĵ� �̰͵��� ť�� �־��ش�.
    }

    while (!q.empty()) { //�������� 
        int from = q.front().first.first;
        int to = q.front().first.second;
        int count = q.front().second;
        q.pop(); //�� �տ����� ����.

        int hcompany = to; //������ ȸ�� �� ���� �켱������ ���� ȸ�縦 ����
        for (int i = 0; i < city_from.size(); i++) {
            if (city_from[i] == hcompany) {
                pq.push({ {city_from[i],city_to[i]},cnt + 1 });
                if (!visit[hcompany]) { //�湮üũ ���ش�
                    visit[hcompany] = 1;
                    fin.push_back(hcompany);
                }
            }
        }
        s = pq.size();
        for (int i = 0; i < s; i++) {
            pair<pair<int, int>, int> temp = pq.top();
            pq.pop();
            int from = temp.first.first;
            int to = temp.first.second;
            int count = temp.second;
            q.push({ {from,to},count }); //���ĵ� �̰͵��� ť�� �־��ش�.
        }

        cnt = count + 1; //����ͺ��� 1 ũ�� ���ߵȴ�.
    }

    for (int i = 0; i < fin.size(); i++) {
        printf("%d ", fin[i]);
    }
    return fin;
}


int main() {
    int city_edges;
    int city_nodes;
    int company;

    cin >> city_edges; //���� ��
    cin >> city_nodes; //���
    cin >> company; //���� ȸ��

    vector<int> city_from(city_edges);
    vector<int> city_to(city_edges);

    int city_from_temp;
    int city_to_temp;
    for (int i = 0; i < city_edges; i++) {
        
        cin >> city_from_temp >> city_to_temp;

        city_from[i] = city_from_temp;
        city_to[i] = city_to_temp;
    }

    vector<int> result = order(city_nodes, city_from, city_to, company);


}