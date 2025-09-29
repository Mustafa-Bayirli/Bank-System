// ******************************************************************
// MUSTAFA BAYIRLI    (300144781)
// ******************************************************************


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>

#include "Bank.h"

using namespace std;

double DepositAccount::rate = 6.50;
double totalAccounts = 0.0;

//******************************************************************
// Basic functions of the BankAccount class
//******************************************************************
inline BankAccount::BankAccount()
{
    accountId = type = updateDate = 0;
    clientName = new char[1];
    balance = 0.0;
}

inline BankAccount::BankAccount(long id, int newType,
                                    char * name, long newDate, double newBalance):
                                    accountId(id), type(newType),
                                    updateDate(newDate), balance(newBalance)
{
     clientName = new char[strlen(name) + 1];
     strcpy(clientName, name);
}

inline BankAccount::~BankAccount()
{
     if (clientName)
     {
          delete [] clientName;
     }
}

inline void BankAccount::setAccountId(long account)
{
     accountId = account;
}

inline void BankAccount::setType(int newType)
{
     type = newType;
}

inline void BankAccount::setClientName(char * name)
{
     if (clientName)
     {
          delete [] clientName;
     }
     clientName = new char[strlen(name) + 1];
     strcpy(clientName, name);
}

inline void BankAccount::setUpdateDate(long newDate)
{
     updateDate = newDate;
}

inline void BankAccount::setBalance(double newBalance)
{
     balance = newBalance;
}

void BankAccount::print() 
{
    cout.setf(ios::fixed);
//     cout.precision(2);
     cout << fixed << setprecision(2);
    cout << accountId << "\t\t\t" << type << "\t" << updateDate << "\t\t" << balance;
}

//******************************************************************
// Basic functions of the DepositAccount class
//******************************************************************
inline DepositAccount::DepositAccount(long id, int newType, char * name,
                                    long newDate, double balanceArg, int nbyear) :
                                    BankAccount(id, newType, name,
                                    newDate, balanceArg), nbyears(nbyear)
{}

inline void DepositAccount::setNbYears(int nbyear)
{
     nbyears = nbyear;
}

void DepositAccount::print() 
{
    Bonus();
    BankAccount::print();
    cout.setf(ios::fixed);
//     cout.precision(2);
     cout << fixed << setprecision(2);

    cout << "\t" << nbyears << "\t\t" << rate << endl;
}

//******************************************************************
// Functions of the class DepositAccount. It allows to calculate
// the annual bonus on deposit accounts.
// Inputs: Nothing
// Outputs: Nothing
//******************************************************************
void DepositAccount::Bonus()
{
  setBalance(getBalance() + (getBalance()* getRate() * (getNbYears())/36000.00));
}



//******************************************************************
// Basic functions of the LoanAccount class
//******************************************************************
inline LoanAccount::LoanAccount(long id, int newType, char * name,
                                    long newDate, double newBalance, int nbyear,
                                    double newRate) : BankAccount(id, newType,
                                    name, newDate, newBalance), nbyears(nbyear), rate(newRate)
{ }

inline void LoanAccount::setNbYears(int nbyear)
{
     nbyears = nbyear;
}

inline void LoanAccount::setRate(double newRate)
{
     rate = newRate;
}

void LoanAccount::print() 
{
    BankAccount::print();
    cout.setf(ios::fixed);
//     cout.precision(2);
     cout << fixed << setprecision(2);
    cout << "\t" << nbyears << "\t\t" << rate << endl;
}

//******************************************************************
// Basic functions of the Transaction class
//******************************************************************
inline Transaction::Transaction(long idTr, int typeTr, long dateTr,
                                    int codeTr = 01, double amountTr):
                                    accountId(idTr), type(typeTr),
                                    date(dateTr), code(codeTr),
                                    amount(amountTr)
{ }

inline void Transaction::setAccountId(long compteTr)
{
     accountId = compteTr;
}

inline void Transaction::setType(int typeTr)
{
     type = typeTr;
}

inline void Transaction::setDate(long dateTr)
{
     date = dateTr;
}

inline void Transaction::setCode(int codeTr)
{
     code = codeTr;
}

inline void Transaction::setAmount(double amountTr)
{
     amount = amountTr;
}




//****************************************************************************
// Purpose: Sort a list of bank accounts in ascending order of ids and types.
//
// WARNING: This sort leaves the last account (of id 0) of the list which has 
// its position to assure the tests of end of list later !!!
//
// Inputs: listAccount(BankAccount *), a list of bank accounts.
// Outputs: listAccount(BankAccount *), sorted list of bank accounts.
//****************************************************************************
void sortAccounts(BankAccount ** list)
{
     BankAccount * temp = nullptr;

     //loop for sorting the account based on the ID 
     for(int i=0;i<K_SizeMax;i++){				
          for(int j=0;j<K_SizeMax-1;j++){
               if(list[j+1]->getAccountId()==0){
                    break;
               }else if(list[j]->getAccountId() > list[j+1]->getAccountId()){
                    temp = list[j];
                    list[j] = list[j+1];
                    list[j+1] = temp;
               }
          }
    }
    
    //loop for sorting the account based on the type
    string typeName1;
    string typeName2;
    for(int i=0;i<K_SizeMax;i++){				
         for(int j=0;j<K_SizeMax-1;j++){
              if(list[j+1]->getAccountId()==0){
                   break;
               }else if(list[j]->getType() > list[j+1]->getType()){
                    typeName1=list[j]->getClientName();
                    typeName2=list[j+1]->getClientName();
                    if(typeName1 == typeName2){
                         temp = list[j];
                         list[j] = list[j+1];
                         list[j+1] = temp;
                    }
               }
          }
     }

}

//******************************************************************
// Purpose: This function reads the file 'clients.txt' and builds 
// an array containing the different bank accounts of customers.
//
// Inputs: Nothing
// Output: listAccount(type: BankAccount *), the list of bank 
//         accounts read from the file 'clients.txt'.
//******************************************************************
BankAccount ** readAccounts()
{
    ifstream inputFile("clients.txt");	// Opening the input file
    if (!inputFile)            		// If the file is not found...
    {
        cout << "File not found !!!" << endl;
        exit(0);
    }

    BankAccount ** listAccounts = new BankAccount*[K_SizeMax];
    if (!listAccounts) {
        cout << "Full memory. !!!" << endl;
        return listAccounts;
    }

    BankAccount ** pAccount = listAccounts;
	 
    long accountRead, dateRead;
    int TypeRead, nbyearRead, counter = 0;
    double balanceRead, RateRead;
    char nameRead[60];
	 
    inputFile >> accountRead >> TypeRead >> dateRead >> balanceRead >> nbyearRead >> RateRead;
    inputFile.getline(nameRead, 60);
	 

    while (inputFile && (counter < K_SizeMax-1)){
        // YOU HAVE TO DO SOMETHING FROM HERE !!!

          switch (TypeRead) {					//Define the account baseed on the type ..
			case 1:
                    pAccount[0] = new BankAccount(accountRead, TypeRead, nameRead, dateRead, balanceRead);
                    break;

			case 2:
                    pAccount[0] = new BankAccount(accountRead, TypeRead, nameRead, dateRead, balanceRead); 
                    break;

			case 3:
                    pAccount[0] = new DepositAccount(accountRead, TypeRead, nameRead, dateRead, balanceRead, nbyearRead); 
                         break;
			case 4:
				balanceRead = balanceRead + (balanceRead * RateRead * (nbyearRead / 36000.00));		
				pAccount[0] = new LoanAccount(accountRead, TypeRead, nameRead, dateRead, balanceRead, nbyearRead, RateRead);
				break;
			default:
				cout << "Error Happened while readind the Account " << accountRead;
				break;
		}

        // UNTIL THIS POINT.

          inputFile >> accountRead >> TypeRead >> dateRead >> balanceRead >> nbyearRead >> RateRead;
          inputFile.getline(nameRead, 60);
          pAccount++;
          counter++;
    }
     *pAccount = new BankAccount();
     return listAccounts;
}





//*****************************************************************************************
// Purpose: This function validates whether the transaction code 
//          corresponds to the correct account:
//              - 01 ==> account (01: Check, 02: Savings, 03: Deposit and 04: Loan)
//              - 02 ==> account (01: Check, 02: Savings)
//              - 03 ==> account (01: Check).
//
// Inputs: trans (Type: Transaction) an instance of the Transaction class.
// Outputs: true (Type bool) if the transaction matches one of the accounts listed above.
// false (Type bool) otherwise.
//*****************************************************************************************
Bool BankAccount::validateTransaction(const Transaction trans) const
{
    if ( ( (trans.getCode() == 02) && ( isDepositAccount() || isLoanAccount()) ) ||
         ( (trans.getCode() == 03) && ( isDepositAccount() || isLoanAccount() || isSavingsAccount() ) ) )
      {
       return FALSE;
      }
    else
      {
       return TRUE;
      }
        
}





//******************************************************************************
// Purpose: This function is used to execute the transaction already performed 
// (update the balance of an account).
//
// Inputs: trans (Transaction Type), instance of Transaction class
// Outputs: Nothing
//*******************************************************************************
void BankAccount::executeTransaction(const Transaction trans)
{
     if (validateTransaction(trans))
       {
         if (trans.getCode() == 01)    // Deposit
           {
             setBalance(getBalance() + trans.getAmount());
           }
         else 
           { if (trans.getCode() == 02)    // Withdrawal
                {
                  if (getBalance() >= trans.getAmount())
                     { setBalance(getBalance() - (trans.getAmount() + 0.50)); }
                  else {cout << " insufficient balance!! " << endl; }
                }
             else 			// Check
                {
                  if (getBalance() >= trans.getAmount())
                     { 
                       setBalance(getBalance() - trans.getAmount());
                     }
                  else {cout << " insufficient balance!! " << endl; }
                }
           }
                 
       }   
 
}

//***********************************************************************
// Purpose: This function is used to execute a read transaction
// (updating the balance of the loan account).
//
// Inputs: trans (Transaction Type), instance of the Transaction class
// Outputs: Nothing
//***********************************************************************
void LoanAccount::executeTransaction(const Transaction trans)
{
     if (validateTransaction(trans))
     {
        if (trans.getCode() == 01)    // Deposit
        {
          setBalance(getBalance() - trans.getAmount());
         
        }
     }
}





//*************************************************************************
// Purpose: This function allows to read the file 'transact.txt' 
//          and to update the accounts concerned by the transactions read.
//
// Inputs: listAccount (type BankAccount *), the list of bank accounts.
// Output: Nothing.
//*************************************************************************
void updateAccounts(BankAccount ** listAccounts) {
     ifstream inputFile("transact.txt");	// Opening the input file

     if (!inputFile)            		// If the file is not found...
     {
          cout << "Transaction File not found." << endl;
		return;
	}
     long accountRead, dateRead;
     int typeRead, transCodeRead, counter = 0;
	double amountRead;
     bool validationTrans;

     inputFile >> accountRead >> typeRead >> dateRead >> transCodeRead >> amountRead;

     while(inputFile && (counter < K_SizeMax - 1)) {
          for (int i = 0; i < K_SizeMax; i++){

               if (listAccounts[i]->getAccountId() == 0) {	// Account ID doesn't exist  or valid ...
				
				break;
			}

               //find the account and type
               if (listAccounts[i]->getAccountId() == accountRead && listAccounts[i]->getType() == typeRead) {
                    Transaction trans(accountRead, typeRead, dateRead, transCodeRead, amountRead);
				if (listAccounts[i]->validateTransaction(trans)) {
                         listAccounts[i]->executeTransaction(trans);
				}
				else {
					break;  
                    }                    
               }
          }
		inputFile >> accountRead >> typeRead >> dateRead >> transCodeRead >> amountRead;		
		counter++;
	}
}


//******************************************************************************
// Purpose: This function displays the list of bank accounts for all customers.
//
// Inputs: listAccount (type: BankAccount *), the list of bank accounts.
// Outputs: Nothing
//******************************************************************************
void displayAccounts(BankAccount ** listAccounts)
{
    cout << endl << endl << endl;
    
    Bool find[K_SizeMax];
    for(int k = 0; k < K_SizeMax; k++) {find[k] = FALSE;}

    cout << "               THE REPORT OF THE BANK ACCOUNTS OF CLIENTS" << endl;
    cout << "               ------------------------------------------" << endl << endl;

    int i = 0;
    double totalAccount = 0;
    string currentClient;
    
    for(i = 0;i<K_SizeMax;i++){
         if (listAccounts[i]->getAccountId()==0){		// no account to be displayed...
               break;
          }
          
          if (currentClient == listAccounts[i]->getClientName()){ }
          else{								
               if(currentClient!=""){
                    cout << "\t\t\t\t\t\t----------\t\t\t\t";
                    cout << endl;
                    cout<<" \t\t TOTAL ACCOUNTS: "<<totalAccount<<endl;
                    cout<<endl;
                    cout<<endl;
                    totalAccount = 0;
               }
               cout << "         Client Name: " << listAccounts[i]->getClientName() << endl<< endl;   // get the client name then print it ...
               currentClient = listAccounts[i]->getClientName();
               
               cout.precision(2);   // two digits after the decimal point...
               cout << "Bank Account \t\t" << "Type \t" << "Update Date \t" << "Balance \t" << "Nb.Years \t" << "Rate \t" << endl;
               cout << "------------ \t\t" << "---- \t" << "----------- \t" << "------- \t" << "-------- \t" << "---- \t" << endl;
          
          }
          
          if(listAccounts[i]->isDepositAccount()){
               dynamic_cast<DepositAccount*>(listAccounts[i])->print();   // DepositAccount. 
               
          }else if (listAccounts[i]->isLoanAccount()){
               dynamic_cast<LoanAccount*>(listAccounts[i])->print();      //LoanAccount.
               
          }else{
               listAccounts[i]->print();        // Other types...
          }
          
          totalAccount += listAccounts[i]->getBalance();   // get the total balance
          cout<<endl;
     }
     cout << endl;
     cout << "\t\t\t\t\t\t----------\t\t\t\t";
     cout << endl;
	cout << "\t\t TOTAL ACCOUNTS: "  <<totalAccount << endl;
     totalAccount = 0;
	
}


int main()
{
    BankAccount ** list = readAccounts();
    sortAccounts(list);
    displayAccounts(list);
    updateAccounts(list);
    cout << endl << endl;
    cout << "               ************************************************" << endl;
    cout << "               * RE-DISPLAY OF DATA AFTER THE UPDATE *" << endl;
    cout << "               ************************************************" << endl;
    displayAccounts(list);
    cout << endl;
    //system("PAUSE");
	return 0;
}
