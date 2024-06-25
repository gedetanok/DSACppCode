#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;


class VertexAdj{
public:
    int num;
    VertexAdj * next;

    VertexAdj(int number){
        next = NULL;
        num = number;
    }
};

class Vertex{
public:
    int num;
    VertexAdj *adjVer;
    Vertex *next;

    Vertex(){
        adjVer =  NULL;
        next = NULL;
    }
};

class Graph{
public:
    Vertex * head;
    Vertex * tail;

    Graph(){
        head = tail = NULL;
    }

    void addVertex(int num){
        Vertex * newVertex = new Vertex();
        newVertex->num = num;

        if(head == NULL){
            head = tail = newVertex;
        }
        else {
            tail->next = newVertex;
            tail = newVertex;
        }
    }

    bool vertexExists(int num){
        Vertex * tempVer = head;
        while (tempVer != NULL){
            if(tempVer->num == num){
                return true;
            }
            else{
                tempVer = tempVer->next;
            }
        }
        
        return false;
    }

    void addEdges(int ver, int adjVer){
        if(!vertexExists(ver)){
            cout << "Vertex doesnt exists" << endl;
            return;
        }

        if(!vertexExists(adjVer)){
            cout << "Vertex for the adjecancy doesnt exists" << endl;
            return;
        }

        Vertex * tempVer = head;
        while (tempVer != NULL){
            if(tempVer->num == ver){
                VertexAdj * newAdjVertex = new VertexAdj(adjVer);
                if(tempVer->adjVer == NULL){
                    tempVer->adjVer = newAdjVertex;
                }
                else{
                    VertexAdj * tempAdj = tempVer->adjVer;
                    while(tempAdj->next != NULL){
                        tempAdj = tempAdj->next;
                    }
                    tempAdj->next = newAdjVertex;
                }
            }

            tempVer = tempVer->next;
        }
    }

    void printGraph(){
        Vertex * tempVer = head;
        while(tempVer != NULL){
            VertexAdj * tempAdj;

            if(tempVer->adjVer != NULL){
                tempAdj = tempVer->adjVer;
                cout << "Vertex (" << tempVer->num << ") ->";
                while(tempAdj != NULL){
                    cout << tempAdj->num << "->";
                    tempAdj = tempAdj->next;
                }
                cout << endl;
            }

            else {
                cout << "Vertex (" << tempVer->num << ") ->" << endl;
            }
            
            tempVer = tempVer->next;
        }
    }

    void BFS(int startVertex) {
        if (!vertexExists(startVertex)) {
            cout << "Starting vertex does not exist." << endl;
            return;
        }

        unordered_set<int> visited;
        queue<int> q;

        q.push(startVertex);
        visited.insert(startVertex);

        cout << "BFT : ";
        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << currentVertex << " ";

            Vertex* tempVer = head;
            while (tempVer != NULL) {
                if (tempVer->num == currentVertex) {
                    VertexAdj* tempAdj = tempVer->adjVer;
                    while (tempAdj != NULL) {
                        if (visited.find(tempAdj->num) == visited.end()) {
                            q.push(tempAdj->num);
                            visited.insert(tempAdj->num);
                        }
                        tempAdj = tempAdj->next;
                    }
                }
                tempVer = tempVer->next;
            }
        }
        cout << endl;
    }

    void DFS(int startVertex) {
        if (!vertexExists(startVertex)) {
            cout << "Starting vertex does not exist." << endl;
            return;
        }

        unordered_set<int> visited;
        stack<int> s;

        s.push(startVertex);
        visited.insert(startVertex);

        cout << "DFT : ";
        while (!s.empty()) {
            int currentVertex = s.top();
            s.pop();
            cout << currentVertex << " ";

            Vertex* tempVer = head;
            while (tempVer != NULL) {
                if (tempVer->num == currentVertex) {
                    VertexAdj* tempAdj = tempVer->adjVer;
                    while (tempAdj != NULL) {
                        if (visited.find(tempAdj->num) == visited.end()) {
                            s.push(tempAdj->num);
                            visited.insert(tempAdj->num);
                        }
                        tempAdj = tempAdj->next;
                    }
                }
                tempVer = tempVer->next;
            }
        }
        cout << endl;
    }

};

int main(){

    Graph g1;

    g1.addVertex(1);
    g1.addVertex(2);
    g1.addVertex(3);
    g1.addVertex(4);
    g1.addVertex(5);

    g1.addEdges(1, 2);
    g1.addEdges(1, 3);
    g1.addEdges(2, 4);
    g1.addEdges(3, 5);

    g1.printGraph();

    g1.DFS(1);
    g1.BFS(1);

    return 0;
}