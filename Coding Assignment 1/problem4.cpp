#include<bits/stdc++.h>
using namespace std;

// structure of a record
typedef struct Record {
    long long nhs_num;
    string name;
    string email;
    string gender;
} Record;

const int N = 1000;
const long long PRIME = 10000000019LL;

struct HashFunctions {

    long long a , p , m ;
    void initialize(long long M , long long P){
        m = M;
        p = P;
        a = 1 + rand() % (p-1);
        return;
    }
    long long apply(long long item){
        __int128 product = (__int128)a * (__int128)item;
        return (long long)((product)%p)%m;
    }

};

Record dataset[N];
int total_records = 0;

// first level hashing

HashFunctions h1;
int m1;
int bin_sizes[5000] = {0}; // for m = 5*n
int bin_indices[5000][1000]; // store indices of records in dataset

// second level hashing

HashFunctions h2[5000];
Record* second_level[5000] = {NULL}; // dynmaic arrays
int second_level_sizes[5000] = {0}; // sizes of each second level table

// build static dictionary function
void buildDictionary(){
    m1 = 5*total_records;
    bool check = false;
    while(!check){
        // reset everything to zero
        for(int i=0;i<m1;i++){
            bin_sizes[i] = 0;
        }
        h1.initialize(m1,PRIME);
        // assign all the records
        bool valid = true;
        for(int i=0;i<total_records;i++){
            int index_at_level_1 = h1.apply(dataset[i].nhs_num);
            // if(bin_sizes[index_at_level_1] < N){
            //     bin_indices[index_at_level_1][bin_sizes[index_at_level_1]] = i;
            //     bin_sizes[index_at_level_1]++;
            // } else {
            //     for(int j=0; j<m1; j++) {
            //         bin_sizes[j] = 0;
            //     }
            //     break; 
            // }
            if(bin_sizes[index_at_level_1] >= 1000){
                valid=false;break;
            }
            bin_indices[index_at_level_1][bin_sizes[index_at_level_1]]=i;
            bin_sizes[index_at_level_1]++;
        }
        if(!valid){
            continue;
        }
        // check sum
        long long int sum = 0;
        for(int i=0;i<m1;i++){
            sum = sum + (long long)(bin_sizes[i])*(bin_sizes[i]);
        }
        if(sum <= 2*m1){
            check = true;
        }


    }

    // second level hashing is applied

    for(int i=0;i<m1;i++){
        int l_i = bin_sizes[i];
        if(l_i  == 0){
            second_level[i] = NULL;
            second_level_sizes[i] = 0;
            continue;
        }
        int m2 = 10*l_i * l_i;
        second_level_sizes[i] = m2;

        bool placed = false;
        while(!placed){
            Record* table = new Record[m2]();
            bool* used = new bool[m2]();
            for(int j=0;j<m2;j++){
                used[j] = false;
            }
            HashFunctions h;
            h.initialize(m2 , PRIME);
            placed = true;
            for(int j=0;j<l_i;j++){
                int index = bin_indices[i][j];
                long long int position = h.apply(dataset[index].nhs_num);
                if(used[position]){
                    placed = false;
                    break;
                }
                used[position] = true;
                table[position] = dataset[index];
            }

            if(placed){
                h2[i] = h;
                second_level[i] = table;
                delete[] used;
            }else{
                delete[] table;
                delete[] used;
            }

        }






    }

}

// search for a key and print out the data in that record
void search(long long int key){
    int i = h1.apply(key);
    if(i<0 || i>=m1 || second_level_sizes[i] == 0 || second_level[i] == NULL){
        cout << "Key not found" << endl;
        return;
    }
    int position = h2[i].apply(key);
    if (position < 0 || position >= second_level_sizes[i]) {
        cout << "Key not found" << endl;
        return;
    }
    if(position < second_level_sizes[i] && second_level[i][position].nhs_num == key){
        Record found = second_level[i][position];
        cout << found.name << ", " << found.email << ", " << found.gender << endl;
    }else{
        cout << "Key not found" << endl;
        
    }



return;
}

// function to process the csv file and store dataset

void readCSVFile(string file_name){

    ifstream file(file_name.c_str());
    if(!file.is_open()){
        cerr << "Error: could not open file!" << file_name << endl;
        exit(1);
    }
    string line;
    
    bool first_row = true;
    while(getline(file,line)){

        if(line.empty()){
            continue;
        }
        if(first_row){
            first_row = false;
            continue;
        }
        stringstream ss(line);
        string serial,nhs_num_string , name , email , gender;

        // skip serial number column
        getline(ss,serial,',');
        // now read fields
        getline(ss,nhs_num_string,',');
        getline(ss,name,',');
        getline(ss,email,',');
        getline(ss,gender);


        dataset[total_records].nhs_num = stoll(nhs_num_string);
        dataset[total_records].name = name;
        dataset[total_records].email = email;
        dataset[total_records].gender = gender;
        total_records++;
        if(total_records >= N){
            break;
        }
    }

    file.close();

}


// main function

int main(){

srand(time(0));
    readCSVFile("dataset.csv");

    // builds dictionary
    buildDictionary();

    // search for input key
    long long int key;
    cin >> key;
    search(key);

    return 0;
}