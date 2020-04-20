#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class TicTacToe{
// time complexity O(n)
private:
    vector<int> rows, cols;
    int diag = 0, rev_diag = 0;
    int _n;
public:
    TicTacToe(int n) : rows(n), cols(n), _n(n) {}

    int move(int row, int col, int player){
        int add = player == 1 ? 1 : -1;
        rows[row] += add;
        cols[col] += add;
        diag += row == col ? add : 0;
        rev_diag += row == _n - col - 1 ? add : 0;
        if (abs(rows[row]) == _n || abs(cols[col]) == _n || abs(diag) == _n || abs(rev_diag) == _n){
            return player;
        }
        return 0;
    }
};

int main(){
    /*
    TicTacToe* toe = new TicTacToe(3);
    cout << toe->move(0, 0, 1) << "\n";
    cout << toe->move(0, 2, 2) << "\n";
    cout << toe->move(2, 2, 1) << "\n";
    cout << toe->move(1, 1, 2) << "\n";
    cout << toe->move(2, 0, 1) << "\n";
    cout << toe->move(1, 0, 2) << "\n";
    cout << toe->move(2, 1, 1) << "\n";
    */
    TicTacToe* toe = new TicTacToe(2);
    cout << "player 1" << " ";
    cout << toe->move(0, 1, 1) << "\n";
    cout << "player 2" << " ";
    cout << toe->move(1, 1, 2) << "\n";
    cout << "player 1" << " ";
    cout << toe->move(1, 0, 1) << "\n";
    return 0;
}