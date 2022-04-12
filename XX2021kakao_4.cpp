/*
제조 회사가 특정 도시에 있습니다.

그들의 상품은 양방향 도로로 연결된 다른 도시로 배송되어야하지만

일부 도시는 읽기가 연결되지 않아 접근이 불가능할 수 있습니다.

배달 순서는 먼저 거리에 따라 결정된 다음 우선 순위에 따라 결정됩니다.

도시의 수, 도로를 통한 연결 및 제조 회사가 위치한 도시를 고려하여 상품이 배송 될 도시의 순서를 결정합니다.

// 그래프가 존재하고 수가 작은순서, 가까운순으로 그 회사를 출력해주면 된다.
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

//테케 다틀림


/*
int visit[10001] = { 0, };
vector <int> fin;

vector<int> order(int city_nodes, vector<int> city_from, vector<int> city_to, int company) {
    priority_queue <pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq; //pq 생성
    int cnt = -1;
    int newcp = company;
    for (int i = 0; i < city_from.size(); i++) {
        if (city_from[i] == 1) {
            pq.push({ {city_from[i],city_to[i]},cnt + 1 });
        }
    }
    newcp++;
    cnt++;
    while (!pq.empty()) { //빌때까지 
        int hcompany = newcp; //현재의 회사
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
        cnt = count + 1; //현재것보다 1 크게 들어가야된다.
        company = to; //회사 재설정
        if (!visit[newcp]) {
            visit[newcp] = 1;
            fin.push_back(newcp);
        }
        pq.pop(); //이 노드는 뽑아준다.
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


// pq가 제대로 작동하는지만 확인해보자

vector<int> order(int city_nodes, vector<int> city_from, vector<int> city_to, int company) {
    queue < pair<pair<int, int>, int>> q; //q 생성
    priority_queue < pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq; // 자동 정렬을 위한 pq 생성
    //priority_queue < pair<pair<int, int>, int>> pq; //

    int cnt = 0;
    for (int i = 0; i < city_from.size(); i++) {
        if (city_from[i] == company) {
            pq.push({ {city_from[i],city_to[i]},cnt }); //pq에 넣으므로 넣으면서 자동 정렬
        }
        //넣은걸 city_from 에서 빼주게된다면?
    }
    int s = pq.size();
    for (int i = 0; i < s; i++) {
        pair<pair<int, int>, int> temp = pq.top();
        pq.pop();
        int from = temp.first.first;
        int to = temp.first.second;
        int count = temp.second;
        q.push({ {from,to},count }); //정렬된 이것들을 큐에 넣어준다.
    }

    while (!q.empty()) { //빌때까지 
        int from = q.front().first.first;
        int to = q.front().first.second;
        int count = q.front().second;
        q.pop(); //맨 앞에것을 뺀다.

        int hcompany = to; //현재의 회사 중 가장 우선순위가 높은 회사를 지정
        for (int i = 0; i < city_from.size(); i++) {
            if (city_from[i] == hcompany) {
                pq.push({ {city_from[i],city_to[i]},cnt + 1 });
                if (!visit[hcompany]) { //방문체크 해준다
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
            q.push({ {from,to},count }); //정렬된 이것들을 큐에 넣어준다.
        }

        cnt = count + 1; //현재것보다 1 크게 들어가야된다.
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

    cin >> city_edges; //연결 선
    cin >> city_nodes; //노드
    cin >> company; //시작 회사

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