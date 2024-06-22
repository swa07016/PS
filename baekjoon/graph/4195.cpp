#include <iostream>
#include <map>
#include <string>

using namespace std;

int T;
int F;
string a, b;

class Person {
public:
    string parent; 
    int size;  // 추가: 집합의 크기를 추적하는 변수
    Person() {}
    Person(string parent) : parent(parent), size(1) {}
};

map<string, Person> persons;

string find(string x) {
    if(persons[x].parent == x) return x;
    return persons[x].parent = find(persons[x].parent);
} 

void Union(string x, string y) {
    string px = find(x);
    string py = find(y);

    if(px != py) {
        persons[py].parent = px;
        persons[px].size += persons[py].size;  // 합칠 때 크기 업데이트
    }
}

int getSize(string x) {
    return persons[find(x)].size;  // 루트 노드의 크기 반환
}

int main() {
    
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> F;
        persons.clear();
        for(int j = 0; j < F; j++) {
            cin >> a >> b;
            if(persons.find(a) == persons.end()) {
                persons[a] = Person(a);
            }
            if(persons.find(b) == persons.end()) {
                persons[b] = Person(b);
            }

            Union(a, b);

            cout << getSize(a) << "\n";
        }
    }

    return 0;
}
