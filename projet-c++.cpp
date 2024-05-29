#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
  string nom;
  string prenom;
  string telephone;
  string email;

  Contact(string nom, string prenom, string telephone, string email) {
    this->nom = nom;
    this->prenom = prenom;
    this->telephone = telephone;
    this->email = email;
  }

  string toString() {
    return "Nom: " + nom + "\nPrénom: " + prenom + "\nTéléphone: " + telephone + "\nEmail: " + email + "\n";
  }
};

vector<Contact> contacts;

void afficherContacts() {
  if (contacts.empty()) {
    cout << "Aucun contact trouvé." << endl;
  } else {
    for (Contact contact : contacts) {
      cout << contact.toString() << endl;
    }
  }
}

void ajouterContact() {
  string nom;
  string prenom;
  string telephone;
  string email;

  cout << "Entrez le nom du contact: ";
  cin >> nom;

  cout << "Entrez le prénom du contact: ";
  cin >> prenom;

  cout << "Entrez le numéro de téléphone du contact: ";
  cin >> telephone;

  cout << "Entrez l'adresse e-mail du contact: ";
  cin >> email;

  contacts.push_back(Contact(nom, prenom, telephone, email));
  cout << "Contact ajouté avec succès." << endl;
}

void modifierContact() {
  if (contacts.empty()) {
    cout << "Aucun contact trouvé." << endl;
  } else {
    int index;

    cout << "Entrez l'index du contact à modifier: ";
    cin >> index;

    if (index < 0 || index >= contacts.size()) {
      cout << "Index invalide." << endl;
    } else {
      Contact contact = contacts[index];

      cout << "Nom actuel: " << contact.nom << endl;
      cout << "Nouveau nom: ";
      cin >> contact.nom;

      cout << "Prénom actuel: " << contact.prenom << endl;
      cout << "Nouveau prénom: ";
      cin >> contact.prenom;

      cout << "Numéro de téléphone actuel: " << contact.telephone << endl;
      cout << "Nouveau numéro de téléphone: ";
      cin >> contact.telephone;

      cout << "Adresse e-mail actuelle: " << contact.email << endl;
      cout << "Nouvelle adresse e-mail: ";
      cin >> contact.email;

      contacts[index] = contact;
      cout << "Contact modifié avec succès." << endl;
    }
  }
}

void supprimerContact() {
  if (contacts.empty()) {
    cout << "Aucun contact trouvé." << endl;
  } else {
    int index;

    cout << "Entrez l'index du contact à supprimer: ";
    cin >> index;

    if (index < 0 || index >= contacts.size()) {
      cout << "Index invalide." << endl;
    } else {
      contacts.erase(contacts.begin() + index);
      cout << "Contact supprimé avec succès." << endl;
    }
  }
}

int main() {
  int choix;

  do {
    cout << "\nMenu principal:" << endl;
    cout << "1. Afficher les contacts" << endl;
    cout << "2. Ajouter un contact" << endl;
    cout << "3. Modifier un contact" << endl;
    cout << "4. Supprimer un contact" << endl;
    cout << "0. Quitter" << endl;
    cout << "Votre choix: ";
    cin >> choix;

    switch (choix) {
      case 1:
        afficherContacts();
        break;
      case 2:
        ajouterContact();
        break;
      case 3:
        modifierContact();
        break;
      case 4:
        supprimerContact();
        break;
      case 0:
        break;
      default:
        cout << "Choix invalide." << endl;
    }
  } while (choix != 0);

  return 0