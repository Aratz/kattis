#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<set>

using namespace std;

struct Patient {
    long long T;
    long long S;
    string name;
};

long long Tc = 0;
long long K = 0;

class Compare {
    public:
        bool operator() (const Patient & a, const Patient & b) {
            long long va = a.S + K*(Tc - a.T);
            long long vb = b.S + K*(Tc - b.T);
            if(va != vb) return  va < vb;
            else return a.name > b.name;
        }
};


int main() {
    priority_queue<Patient, vector<Patient>, Compare> queue;
    set<string> exited;

    long long N;

    cin >> N >> K;

    while(N--) {
        int Q;
        cin >> Q;
        if(Q == 1) {
            long long T, S;
            string M;
            cin >> T >> M >> S;
            Tc = T;
            queue.push(Patient {T, S, M});
        }
        else if (Q == 2) {
            cin >> Tc;
            if(!queue.empty()) {
                Patient p;
                do{
                    p = queue.top(); queue.pop();
                }while(!queue.empty() && exited.find(p.name) != exited.end());
                cout << p.name << "\n";
            }
            else
                cout << "doctor takes a break\n";
        }
        else {
            string M;
            cin >> Tc >> M;
            exited.insert(M);
        }
    }

    return 0;
}
