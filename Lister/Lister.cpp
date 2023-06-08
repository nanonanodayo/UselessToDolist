// Lister.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

/*bool write_binary(std::string filepath, std::vector<string>& vec) {
    std::ofstream fout(filepath, std::ios::out | std::ios::binary);
    fout.write((char*)&vec[0], vec.size() * sizeof(vec[0]));
    fout.close();
    return true;
}
bool read_binary(std::string filepath, std::vector<string>& vec) {
    std::ifstream fin(filepath, std::ios::in | std::ios::binary);
    fin.read((char*)&vec[0], vec.size() * sizeof(vec[0]));
    fin.close();
    return true;
}
*/
int main()
{
    queue<string> ToDo;
    queue<string> Tmp;
   // read_binary("ToDo.bin", ToDo);
    ofstream wiler;
    ifstream reader;
    string filename = "ToDo.txt";
    
    reader.open(filename, std::ios::in);
    
    string reading_line_buffer;
    while (std::getline(reader, reading_line_buffer)) {
     //   cout << reading_line_buffer;
        if (reading_line_buffer == "")continue;
        ToDo.push(reading_line_buffer);
    }
  //  cout << ToDo.front();
    std::string command;
    std::string hoge;
    const int commandnum = 7;
    
    std::string commands[commandnum] = { "in","out","exit","help","delete","list","after"};
    int siz = ToDo.size();
    std::cout << "ToDo管理プログラムへようこそ！"<<endl;
    std::cout << "このコードは特に何も考えられずに作られています！"<<endl;
    cout << "--------------------------------------------------------------------------" << endl;
    std::cout << "コマンドをどうぞ" << endl;
    while (true) {
        getline(cin, command);
        if (command == "In" || command == "in") {
            cout << endl;
            cout << "何を入力しますか？" << endl;
            getline(cin, hoge);
            ToDo.push(hoge);
            cout <<endl<< "\"" << hoge << "\"をリストに登録しました。" << endl;
        }
        else if (command == "Out" || command == "out" ||command=="o") {
            if (ToDo.size() == 0) {
                cout << endl;
                cout << "あなたがやるべきことはありません、よく頑張りましたね。" << endl;
            }
            else {
                cout << endl;
                cout << "次にあなたがやるべきことは\"";
                cout << ToDo.front() << "\"です。頑張ってください。" << endl;
                //ToDo.pop();
            }
           
        }
        else if (command == "Delete" || command == "delete" || command=="d") {
            siz = ToDo.size();
            if (siz == 0) {
                cout << endl;
                cout << "あなたがやるべきことはありません、よく頑張りましたね。" << endl;
            }
            else {
                cout << endl;
                cout << "作業が終わったんですね。"<<ToDo.front()<<"をきちんと削除しましたよ。" << endl;
                ToDo.pop();
                
            }

        }
        else if (command == "Exit" || command == "exit" || command=="e") {
            cout << endl;
            cout << "終了します。エンターキーを押して下さい。" << endl;
           
            string outer;
            siz = ToDo.size();
          //  cout << ToDo.size();
            for (int i = 0; i < siz-1; i++) {
                outer += ToDo.front();
                outer += "\n";
                ToDo.pop();

            }
            outer += ToDo.front();
            ToDo.pop();
           // cout << outer;
            wiler.open(filename, std::ios::out);
            wiler << outer;
            wiler.close();
           // getchar();
            getchar();
            return 0;
        }
        else if (command == "List" || command == "list" || command == "l") {
            siz = ToDo.size();
            cout << endl << "やるべきことを一覧表示します" << endl;
            
            if (siz == 0)cout<<endl << "やるべきことはないですよ。"<<endl;
            else {
                cout << "--------------------------------------------------------------------------" << endl;
                for (int i = 0; i <= siz - 1; i++) {
                    cout << i + 1 << "番目: " << ToDo.front() << endl;
                    ToDo.push(ToDo.front());
                    ToDo.pop();
                }
            }
            //cout << ToDo.size();
        }
        else if (command == "help" || command == "Help") {
            
            cout<<endl << "コマンド一覧を表示します。" << endl;
            cout << "--------------------------------------------------------------------------" << endl;
            for (int i = 0; i < commandnum; i++) {
                cout << commands[i] << endl;
            }
        }
        else if (command == "after" || command == "After") {
            siz = ToDo.size();
            if (siz > 0) {
                cout << endl <<  ToDo.front() << "を後回しにします。必ずやってくださいね。" << endl;
                ToDo.push(ToDo.front());
                ToDo.pop();
            }
            else {
                cout << endl << "後回しにする目標がないよ！" << endl;
            }
        }
        else {
            cout << "対応していないコマンドです。正しいコマンドを入力してください。" << endl;
        }
        cout << "--------------------------------------------------------------------------" << endl;
        std::cout << "コマンドをどうぞ" << endl;
     //   std::cout << "Hello World!\n";

    }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
