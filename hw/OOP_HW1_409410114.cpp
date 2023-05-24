#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;

class NODE{
public:
    int ID;
    int discovered;
    int pred;
    int SDN;
    vector<unsigned int> neighborList;
    map<unsigned int, vector<pair<unsigned int, double>>> routingTable;
    NODE();
    NODE(int _id);
    void shortest_path_store();
    void distribution(int nodes, vector<int> Dst_list);
    void result(int nodes);
};
vector<NODE*> NodeList;

//constructor
NODE::NODE(){
}
NODE::NODE(int _id){
        ID = _id;
        discovered = 0;
        pred = -1;
}

//find shortest path by BFS
int BFS(int src, int dst){
    deque<int> q;
    //initialize NodeList
    for(unsigned int i=0; i<NodeList.size(); i++){
        NodeList[i]->discovered = 0;
        NodeList[i]->pred = -1;
    }
    if(src == dst)
        return 1;
    q.push_back(src);
    NodeList[src]->discovered = 1;

    int currID, adjID;
    NODE* currNODE;
    NODE* adjNODE;

    while(q.size() != 0){
        currID = q.front();
        q.pop_front();
        currNODE = NodeList[currID];

        for(unsigned int i=0; i<currNODE->neighborList.size(); i++){
            adjID = currNODE->neighborList[i];
            adjNODE = NodeList[adjID];
            if(adjNODE->discovered == 0){
                adjNODE->discovered = 1;
                adjNODE->pred = currID;
                q.push_back(adjID);
            }
            if(currNODE->neighborList[i] == dst)
                return 1;
        }
    }

    return 0;
}

//reverse path
vector<int> print(int num, int dst, int nodes){
    vector<int> path; //dst->src
    vector<int> save_path; //src->dst
    int crawl = dst;
    path.push_back(crawl);
    while(NodeList[crawl]->pred != -1){
        path.push_back(NodeList[crawl]->pred);
        crawl = NodeList[crawl]->pred;
    }
    //path from the specific src
    for (int i = path.size()-1; i >= 0; i--){
        save_path.push_back(path[i]);
    }
    return save_path;
}

void NODE::distribution(int nodes, vector<int> Dst_list){
    vector<int> save_path;
    unsigned int next_node = 0;
    double portion = 0;
    for(int i=0; i<Dst_list.size(); i++){
        for(int num=0; num<nodes; num++){
            //shortest path
            BFS(num, Dst_list[i]);
            save_path = print(num, Dst_list[i], nodes);

            if(save_path.size() == 1) //src=dst
                next_node = (unsigned int)(save_path[0]);
            else
                next_node = (unsigned int)(save_path[1]);
            if(NodeList[save_path[0]]->SDN == 1)
                portion = 100;
            else
                portion = -1.0;
            //make routing table
            (NodeList[save_path[0]]->routingTable)[Dst_list[i]].push_back(make_pair(next_node, portion));

            save_path.clear();
        }

    }
    //print ans
    result(nodes);
}

void NODE::result(int nodes){
    map<unsigned int, vector<pair<unsigned int, double>>>::iterator iter;
    for(int i=0 ;i<nodes; i++){
        cout << i << endl;
        for(iter=(NodeList[i]->routingTable).begin(); iter!=(NodeList[i]->routingTable).end(); iter++){
            vector<pair<unsigned int, double>> vec_v = iter->second;
            for(auto &it:vec_v){
                cout << iter->first << " " << it.first << " " ;
                if(it.second==100)
                    cout << it.second << "%" << endl;
                else
                    cout << endl;
            }

        }
    }
}

int main(){
    //input number
    int nodes, SDN_Nodes, Dsts, links, pairs;
    cin >> nodes >> SDN_Nodes >> Dsts >> links >> pairs;

    //store SDN & Dst
    int tmp;
    vector<int> SDN_list;
    vector<int> Dst_list;
    for(int i=0; i<SDN_Nodes; i++){
        cin >> tmp;
        SDN_list.push_back(tmp);
    }
    for(int i=0; i<Dsts; i++){
        cin >> tmp;
        Dst_list.push_back(tmp);
    }
    //neighborList
    int linkID, node1, node2;
    for(int i=0; i<nodes; i++)
        NodeList.push_back(new NODE(i));
    for(int i=0; i<links; i++){
        cin >> linkID >> node1 >> node2;
        NodeList[node1]->neighborList.push_back(node2);
        NodeList[node2]->neighborList.push_back(node1);
    }

    int idx = 0;
    for(int i=0; i<nodes; i++){
        for(int j=idx; j<SDN_list.size(); j++){
            if(i == SDN_list[j]){
                NodeList[i]->SDN = 1;
                idx++;
                break;
            }
            else
                NodeList[i]->SDN = 0;
        }
    }

    //input flow
    int flowID, flowSize, src, dst;
    int flowList[nodes][2];
    for(int i=0; i<nodes; i++){
        flowList[i][0] = 0;
        flowList[i][1] = 0;
    }

    for(int i=0; i<pairs; i++){
        cin >> flowID >> src >> dst >> flowSize;
        flowList[src][0] = dst;
        flowList[src][1] = flowSize;
    }

    NODE N;
    N.distribution(nodes, Dst_list);

    return 0;
}


/*
15 3 1 28 3
2 9 14
0
0 0 5
1 0 10
2 0 12
3 0 14
4 1 2
5 1 3
6 1 4
7 2 3
8 2 10
9 2 11
10 3 4
11 3 6
12 3 7
13 4 8
14 4 9
15 5 6
16 5 7
17 5 9
18 5 10
19 5 14
20 6 7
21 6 10
22 7 9
23 8 9
24 9 13
25 10 12
26 11 12
27 13 14
0 1 0 3
1 2 0 4
2 3 0 5
*/

/*
15 3 2 18 4
0 1 13
0 14
0 0 1
1 0 14
2 1 2
3 1 10
4 1 13
5 2 3
6 3 4
7 4 5
8 5 6
9 6 7
10 7 8
11 7 13
12 8 9
13 9 10
14 10 11
15 11 12
16 12 13
17 13 14
0 14 0 10
1 1 0 20
2 0 14 15
3 3 14 5
*/
/*
0
0 0 100%
14 14 100%
1
0 0 100%
14 10 0% 13 100%
2
0 1
14 3
3
0 2
14 4
4
0 3
14 5
5
0 4
14 6
6
0 5
14 7
7
0 6
14 8
8
0 7
14 9
9
0 8
14 10
10
0 9
14 11
11
0 10
14 12
12
0 11
14 13
13
0 1 50% 7 50%
14 14 100%
14
0 0 100%
14 14 100%
*/
//https://kopu.chat/%E5%AF%A6%E4%BD%9Cgraph%E8%88%87dfs%E3%80%81bfs%E8%B5%B0%E8%A8%AA/#lwptoc19
//https://www.geeksforgeeks.org/shortest-path-unweighted-graph/
