#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    string nomor;
    Node* left;
    Node* right;
    Node(string n, string no): nama(n), nomor(no), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, string nama, string nomor) {
    if (!root) return new Node(nama, nomor);
    if (nama < root->nama) root->left = insertNode(root->left, nama, nomor);
    else if (nama > root->nama) root->right = insertNode(root->right, nama, nomor);
    else cout << "Kontak dengan nama \"" << nama << "\" sudah ada!\n";
    return root;
}

bool searchNode(Node* root, string nama) {
    if (!root) return false;
    if (root->nama == nama) return true;
    if (nama < root->nama) return searchNode(root->left, nama);
    return searchNode(root->right, nama);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << "Nama: " << root->nama << " | Nomor: " << root->nomor << endl;
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << "Nama: " << root->nama << " | Nomor: " << root->nomor << endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << "Nama: " << root->nama << " | Nomor: " << root->nomor << endl;
}

string findMin(Node* root) {
    if (!root) return "(kosong)";
    while (root->left) root = root->left;
    return root->nama;
}

string findMax(Node* root) {
    if (!root) return "(kosong)";
    while (root->right) root = root->right;
    return root->nama;
}

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumNama(Node* root) { 
    if (!root) return 0;
    return 1 + sumNama(root->left) + sumNama(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih;
    string nama, nomor;

    do {
        cout << "\n=== BST Kontak Telepon ===\n";
        cout << "1. Tambah kontak\n2. Cari kontak\n3. Inorder\n4. Preorder\n5. Postorder\n";
        cout << "6. Nama terkecil (A-Z)\n7. Nama terbesar (Z-A)\n8. Jumlah kontak\n9. Total nama (simulasi)\n10. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore(); 

        if (pilih == 1) {
            cout << "Masukkan nama: "; getline(cin, nama);
            cout << "Masukkan nomor telepon: "; getline(cin, nomor);
            root = insertNode(root, nama, nomor);
        } else if (pilih == 2) {
            cout << "Cari nama: "; getline(cin, nama);
            cout << (searchNode(root, nama) ? "Kontak ditemukan!\n" : "Kontak tidak ditemukan!\n");
        } else if (pilih == 3) {
            cout << "\n=== Daftar Kontak (Inorder) ===\n";
            inorder(root);
        } else if (pilih == 4) {
            cout << "\n=== Daftar Kontak (Preorder) ===\n";
            preorder(root);
        } else if (pilih == 5) {
            cout << "\n=== Daftar Kontak (Postorder) ===\n";
            postorder(root);
        } else if (pilih == 6) {
            cout << "Nama terkecil (paling awal alfabet): " << findMin(root) << "\n";
        } else if (pilih == 7) {
            cout << "Nama terbesar (paling akhir alfabet): " << findMax(root) << "\n";
        } else if (pilih == 8) {
            cout << "Jumlah kontak: " << countNodes(root) << "\n";
        } else if (pilih == 9) {
            cout << "Total entri nama (simulasi hitung): " << sumNama(root) << "\n";
        }
    } while (pilih != 10);

    return 0;
}
