#define INF 1000000000
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, string> is;
typedef vector<is> vps;

int count(string s, char c){
    /* Count number of appearances of c */
    int res = 0;
    for(auto i=0; i<s.size(); i++)
        res += (s[i]==c)?1:0;
    return res;
}

int main(){
    string ab;
    while(getline(cin, ab)){
        map<string, vps> adj_list;
        map<string, int> dist;
        map<string, string> ancestor;

        string start, end;
        stringstream streamAB(ab);
        streamAB >> end >> start;

        start += "_out";

        adj_list[start] = vps(); dist[start] = INF;
        adj_list[start+"_out"] = vps(); dist[start+"_out"] = INF;
        adj_list[start].push_back(is(1, start+"_out"));

        adj_list[end] = vps(); dist[end] = INF;
        adj_list[end+"_out"] = vps(); dist[end+"_out"] = INF;
        adj_list[end].push_back(is(1, end+"_out"));

        int n;
        cin >> n;
        string tmp;
        getline(cin, tmp);

        while(n--){
            string line;
            getline(cin, line);
            stringstream stream(line);
            int nword = count(line, ' ') + 1;
            vector<string> names;
            while(nword--){
                string name;
                stream >> name;
                if(!name.empty())
                    names.push_back(name);
            }

            for(auto s : names){
                for(auto t : names){
                    if(s==t)
                        continue;

                    if(adj_list.find(s)==adj_list.end()){
                        adj_list[s] = vps(); dist[s] = INF;
                        adj_list[s+"_out"] = vps(); dist[s+"_out"] = INF;

                        adj_list[s].push_back(is(1, s+"_out"));
                    }
                    adj_list[s+"_out"].push_back(is(names.size()-2, t));
                }
            }
        }

        dist[start] = 0;
        ancestor[start] = start;

        priority_queue<is, vps, greater<is>> pq; pq.push(is(0, start));
        while(!pq.empty()){
            is edge = pq.top(); pq.pop();
            int d = edge.first; string u = edge.second;
            if(d > dist[u]) continue;
            for(auto new_edge : adj_list[u]){
                if(dist[u] + new_edge.first < dist[new_edge.second]){
                    ancestor[new_edge.second] = u;
                    dist[new_edge.second] = dist[u] + new_edge.first;
                    pq.push(is(dist[new_edge.second], new_edge.second));
                }
            }
        }

        if(dist[end] < INF){
            cout << dist[end];

            string current = end;
            while(current != ancestor[current]){
                if(current.find("_out")==string::npos)
                    cout << " " << current;
                current = ancestor[current];
            }
            current.erase(current.size()-4, current.size());
            cout << " " << current << "\n";
        }
        else
            cout << "impossible\n";
    }
    return 0;
}
