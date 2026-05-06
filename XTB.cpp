#include<iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;
//string globalName , globalPassword;
int numberOfSuccessiveTransactions = 0 , numberOfFailedTransactions = 0;
void welcome()
{
  cout<<"***************************************************"<<endl;
  cout<<"****************WELCOME TO XTB BANK****************"<<endl;
  cout<<"***************************************************"<<endl<<endl;
}
void checkAmount(double &amount)
{
  cout<<"Your Current ballance is: "<<"\033[92m"<<amount<<"$"<<"\033[0m"<<endl<<endl;
  //return amount;
}
double deposit(double &amount)
{
  double amountPrevious = amount;
  cout<<"Enter amount to Deposit: ";
  cin>>amount;
  amount += amountPrevious;
  if (amount<0)
  {
    std::cout << "\nEnter Valid Inputs!! " << std::endl;
    return 0;
  }
  else{
    cout<<"\033[92m"<<"Amount Deposited Succesfully!"<<"\033[0m"<<endl<<endl;
    return amount;
  }
}
//double withdraw(double &amount)
void withdraw(double &amount)
{
  double withdrawAmount;
  cout<<"\nEnter amount to Withdraw: ";
  cin>>withdrawAmount;
  if(withdrawAmount < 0)
  {
    std::cout << "\nEnter Valid Inputs!! " << std::endl;
    //return 0;
  }
  else if(withdrawAmount == 0)
  {
    std::cout << "\nYou can't withdraw least amount!! " << std::endl;
    //return 0;
  }
  else if(amount == 0)
  {
    std::cout << "\nLow Balance!! " << std::endl;
    //return 0;
  }
  else if((amount - withdrawAmount)<0)
  {
    cout<<"\nAmount Exceeding Current Balance!!";
    //return 0;
  }
  else if ((amount - withdrawAmount)<10)
  {
    /* code */
    cout<<"\nYou cannot withdraw Full Amount!!\nService Charges Denials!!";
  }
  
  // else if((amount - withdrawAmount)>0 || (amount - withdrawAmount)<10)
  // {
  //   cout<<"\nYou can't withdraw least amount";
  //   //return 0;
  // }
  else 
  {
    int tax;
    tax = withdrawAmount * 0.05;
    cout<<"5% Tax Applied"<<endl;
    //return (amount - tax);
    amount -= tax;
  }
}

void transaction(double &amount)
{
    string transactionID; 
    double payAmount;
    cin.ignore();
    cout << "Enter Transaction ID: e.g(AX47B1) :" <<endl;
    getline(cin, transactionID);
    //cout << "\n3x Here;";
    
    cout << endl << "Enter Pay Amount: ";
    cin >> payAmount;
    if(payAmount < 0)
      std::cout << "\nEnter Valid Inputs!! " << std::endl;

    else if (payAmount > amount)
    {
        std::cout << "\nLow Balance! Payment revoked!" << endl;
        numberOfFailedTransactions++;
        //return 0;
    }
    else
    {
        std::cout <<endl<< "\033[43m" << "Verifying Your Payment" << "\033[0m" << endl;
        int tax = (payAmount * 0.05);
        cout << "5% Tax Applied" << endl;
        std::cout << "\033[42m" << "Payment Successful" << "\033[0m" << endl << endl;
        //return amount - tax;
        amount -= (payAmount + tax);
        numberOfSuccessiveTransactions++;
    }
}
void paySpecial(double &amount)
{
    string transactionID; 
    double payAmount;
    cin.ignore();
    cout << "Enter Transaction ID: e.g(AX47B1) :" <<endl;
    getline(cin, transactionID);
    //cout << "\n3x Here;";
    
    cout << endl << "Enter Pay Amount: ";
    cin >> payAmount;

    if(payAmount < 0)
      std::cout << "\nEnter Valid Inputs!! " << std::endl;

    else if (payAmount > amount)
    {
        std::cout <<endl<< "\033[43m" << "Verifying Your Payment" << "\033[0m" << endl;
        this_thread::sleep_for(chrono::milliseconds(3200));
        std::cout << "Low Balance! Payment revoked!" << endl;
        numberOfFailedTransactions++;
        //return 0;
    }
    else
    {
        std::cout <<endl<< "\033[43m" << "Verifying Your Payment" << "\033[0m" << endl;
        this_thread::sleep_for(chrono::milliseconds(3200));
        //int tax = amount - payAmount + (payAmount * 0.05);
        std::cout <<endl<< "\033[43m" << "No Tax applied" << "\033[0m" << endl;
        //cout << "No Tax Applied" << endl;
        std::cout << "\033[46m" << "Payment Successful" << "\033[0m" << endl << endl;
        //return amount - tax;
        amount = amount - payAmount;
        numberOfSuccessiveTransactions++;
    }
}
void benevolent(double &amount)
{
  char ch;double charity;
  std::cout <<endl<< "\033[93m" << "A benevolence fund serves as a critical safety net, offering immediate financial assistance to those facing sudden and severe hardships. Managed by nonprofit organizations, these funds provide essential support to help individuals and families navigate through their most challenging times." << "\033[0m" << endl;
  std::cout << "1. Zakat \t\t2. Charity " << std::endl;
  std::cout <<endl<< "Enter Welfare Choice : " << std::endl;
  cin>>ch;
  if(ch=='1')
  {
    if ((amount - (amount * 0.25))<0)
      cout<<"\nInvalid Funds!";
    else if (amount <= 0){
      std::cout << "\nLow Balance! Payment revoked!" << endl;
      numberOfFailedTransactions++;
    }
      //cout<<"\nInvalid Funds!";
    else{
      std::cout << "\033[46m" << "\n2.5% Zakat Deducted Sucessfully" << "\033[46m" << endl;
      std::cout << "\033[46m" << "\n2.5% of "<<amount<<" is " <<amount * (2.5/100.0)<< "\033[0m" << endl;
      amount -= (amount * (2.5/100.0));
      numberOfSuccessiveTransactions++;
    }
  }
  else if(ch=='2')
  {
    cout<<"\nEnter Amount to Perform Charity: ";cin.ignore();
    cin>>charity;
    if (charity < 0)
      cout<<"\nInvalid Funds!";
    else if (amount - charity <0){
      std::cout << "\nLow Balance! Payment revoked!" << endl;
      numberOfFailedTransactions++;
    }
    else{
      amount -= charity;
      std::cout << "\033[46m" << "Charity Deducted Sucessfully!" << "\033[0m" << endl;
      numberOfSuccessiveTransactions++;
    }
  }
  else std::cout <<endl<< "Invalid Inputs! " << std::endl;
}

void bonus(double &amount)
{
  string coupon;
  cin.ignore();
  cout<<endl<<"Enter Valid Coupon Code: ";
  getline(cin , coupon);
  if (amount < 0)
    cout<<"\nCoupon Failed to Retrieve!";
  else if (amount == 0)
    {
      amount +=5.0;
      std::cout << "\033[46m" << "Coupon Applied Sucessfully" << "\033[0m" << endl;
      std::cout << "\033[46m" << "5% Increment Sucessfull" << "\033[0m" << endl;
    }
  else{
    amount += ((5.0/amount)*100);
    std::cout << "\033[46m" << "Coupon Applied Sucessfully" << "\033[0m" << endl;
    std::cout << "\033[46m" << "5% Increment Sucessfull" << "\033[0m" << endl;
  }
}

void feeSubmittion(double &amount)
{
  double payable;//1
  char feeSubmittionChoice;string uniName , studentName, voucher;//1
  string billType , billRecipant, billId;double billAmount;//2
  string challanName, challanRecipantName , challanID; double challanAmount;//3
  feeSubmittionChoiceLabel:
  cout<<"\nChoose Your Desire Fee Option:"<<endl;
  cout<<"1. University Fee \t\t2. Utility Bills"<<endl;
  cout<<"3. Special Challan "<<endl<<endl;
  cout<<"Enter your Choice: ";cin>> feeSubmittionChoice;
  if (feeSubmittionChoice == '1')
  {
    cout << "\033[33m" << "\tUniversity Fee Portal" << "\033[0m" << endl;cin.ignore();
    cout<<"Enter University/Institute Name: ";getline(cin , uniName);
    cout<<endl<<"Enter Student Name: ";getline(cin , studentName);
    label:
    cout<<endl<<"Enter 10 Character Voucher Code: ";getline(cin , voucher);
    if(voucher.length()<10)
    {
      cout <<endl<< "\033[41m" << "Enter Valid Voucher Code!" << "\033[0m" << endl;
      goto label;
    }
    else{
      label1:
      std::cout <<endl<< "Enter Payable: ";cin>>payable;
      if(payable < 0)
      {
        cout <<endl<< "\033[41m" << "Invalid Inputs!" << "\033[0m" << endl;
        goto label1;
      }
      else if(amount - payable <= 0)
      {
        std::cout <<endl<< "\033[43m" << "Verifying Your Payment" << "\033[0m" << endl;
        this_thread::sleep_for(chrono::milliseconds(3200));
        cout <<endl<< "\033[41m" << "Low Balance! Please Recharge" << "\033[0m" << endl;
        numberOfFailedTransactions++;
        //goto label1;
      }
      else
      {
        amount -= payable + (payable * 0.05);
        cout <<endl<< "\033[42m" << "Voucher "<<voucher<<" Successfully Submitted for "<<studentName << "\033[0m" << endl;
        cout <<endl<< "\033[92m" << "5% Tax Applied" << "\033[0m" << endl;
        numberOfSuccessiveTransactions++;
      }
    }
  }
  else if (feeSubmittionChoice == '2')
  {
    cin.ignore();
    std::cout <<endl<< "Enter Utility Bill Type: ";getline(cin , billType);
    std::cout <<endl<< "Enter Utility Bill Recipant: ";getline(cin , billRecipant);
    std::cout <<endl<< "Enter 10 Character Bill ID: ";getline(cin , billId);
    utilityBillLabel:
    std::cout << "Net Payable: ";cin>>billAmount;
    if(billAmount < 0)
    {
      cout <<endl<< "\033[41m" << "Invalid Inputs" << "\033[0m" << endl;
      goto utilityBillLabel;
    }
    else if(amount - (billAmount + (billAmount * 0.18)) <= 0)
    {
      std::cout <<endl<< "\033[43m" << "Verifying Your Payment" << "\033[0m" << endl;
      this_thread::sleep_for(chrono::milliseconds(3200));
      cout <<endl<< "\033[41m" << "Low Balance! Please Recharge" << "\033[0m" << endl;
      numberOfFailedTransactions++;
      //cout <<endl<< "\033[41m" << "Invalid Funds" << "\033[0m" << endl;
      //goto utilityBillLabel;
    }
    else
    {
      amount -= billAmount + (billAmount * 0.18);
      std::cout <<endl<< "\033[43m" << "Verifying Your Payment" << "\033[0m" << endl;
      this_thread::sleep_for(chrono::milliseconds(3200));
      cout <<endl<< "\033[42m" << "Utility Bill("<<billType<<") using ID "<<billId<<" has been Submitted Sucessfully!" << "\033[0m" << endl;
      cout <<endl<< "\033[92m" << "18% Tax Applied" << "\033[0m" << endl;
      numberOfSuccessiveTransactions++;
    }
  }
  else if (feeSubmittionChoice == '3')
  {
    cin.ignore();
    std::cout <<endl<< "Enter Challan Genre: ";getline(cin , challanName);
    std::cout <<endl<< "Enter Challan Recipant Name: ";getline(cin , challanRecipantName);
    std::cout <<endl<< "Enter 10 Character Bill ID: ";getline(cin , challanID);
    challanLabel:
    std::cout << "Net Payable: ";cin>>challanAmount;
    if(challanAmount < 0)
    {
      cout <<endl<< "\033[41m" << "Invalid Inputs" << "\033[0m" << endl;
      goto challanLabel;
    }
    else if(amount - (challanAmount + (challanAmount * 0.18)) <= 0)
    {
      std::cout <<endl<< "\033[43m" << "Verifying Your Payment" << "\033[0m" << endl;
      this_thread::sleep_for(chrono::milliseconds(3200));
      cout <<endl<< "\033[41m" << "Low Balance! Please Recharge" << "\033[0m" << endl;
      //cout <<endl<< "\033[41m" << "Invalid Funds" << "\033[0m" << endl;
      //goto challanLabel;
    }
    else
    {
      
      amount -= challanAmount + (challanAmount * 0.18);
      std::cout <<endl<< "\033[43m" << "Verifying Your Payment" << "\033[0m" << endl;
      this_thread::sleep_for(chrono::milliseconds(3200));
      cout <<endl<< "\033[42m" << "Challan("<<challanName<<") using ID "<<challanID<<" has been Submitted Sucessfully!" << "\033[0m" << endl;
      cout <<endl<< "\033[92m" << "18% Tax Applied" << "\033[0m" << endl;
      numberOfSuccessiveTransactions++;
    }
  }
  else{
    cout <<endl<< "\033[41m" << "Invalid Inputs!" << "\033[0m" << endl;
    this_thread::sleep_for(chrono::milliseconds(1200));
    goto feeSubmittionChoiceLabel;
  }
    
}
void privacyAndPolicy()
{
  cout <<endl<<endl<< "\033[92m" << "\t\t\tBank Privacy and Policy Portal" << "\033[0m" << endl;
  cout <<endl<<endl<< "\033[92m" << "1. Welcome to XTB Banking System! Your privacy is critically important to us. This Privacy Policy outlines how we collect, use, disclose, and protect your personal information.\n2. Data Privacy We are committed to safeguarding the privacy of your personal data. We collect only the data necessary to provide our services and ensure it is protected against unauthorized access and breaches." << "\033[0m" << endl;
  cout <<endl<< "\033[92m" << "3. Regulatory Compliance We comply with all applicable laws and regulations, including the Gramm-Leach-Bliley Act (GLBA), which requires us to protect the confidentiality and security of your personal information.\n4. Cybersecurity Measures To protect your data, we implement a range of security measures, including but not limited to: " << "\033[0m" << endl;

  cout <<endl<< "\033[92m" << "\tEncryption: All sensitive information is encrypted both in transit and at rest." << "\033[0m" << endl;

  cout <<endl<< "\033[92m" << "\tAccess Controls: Strict access controls ensure that only authorized personnel can access your data." << "\033[0m" << endl;

  cout <<endl<< "\033[92m" << "\tSecurity Audits: Regular security audits and assessments are conducted to identify and mitigate potential vulnerabilities." << "\033[0m" << endl;

  cout <<endl<< "\033[92m" << "5. Customer Consent We obtain your explicit consent before collecting, using, or sharing your personal data. You have the right to withdraw your consent at any time.\n6. Data Minimization We adhere to the principle of data minimization, collecting only the data that is necessary for the purposes for which it is processed." << "\033[0m" << endl;

  cout <<endl<< "\033[92m" << "7. Privacy by Design We incorporate privacy considerations into the design and development of our systems and processes, ensuring that your privacy is protected by default.\n8. Risk Management We conduct regular risk assessments to identify, assess, and mitigate privacy risks. This proactive approach helps us to manage potential threats to your data effectively." << "\033[0m" << endl;

  cout <<endl<< "\033[92m" << "9. Ethical Considerations We are committed to using your data ethically and responsibly. Our practices are guided by ethical principles to ensure that your information is treated with the utmost respect.\n10. Transparency and Accountability We are transparent about our data practices and hold ourselves accountable for protecting your personal information. You can always contact us for more information about our privacy practices." << "\033[0m" << endl;
  cout <<endl<< "\033[92m" << "11. Changes to This Policy We may update this Privacy Policy from time to time. We will notify you of any changes by posting the new Privacy Policy on our website. Your continued use of our services after any changes indicates your acceptance of the updated policy.\n12. Contact Us If you have any questions or concerns about this Privacy Policy or our data practices, please contact us at [Contact Information]" << "\033[0m" << endl;

}
void customerSupport()
{
  cout <<endl<< "\033[33m" << "\t\tCostumer Support Section" << "\033[0m" << endl<<endl;
  std::cout << "Nearby Bank Branch : XTB Limited" << std::endl;
  std::cout << "HR                 :    +92 67xxxxxxxx" << std::endl;
  std::cout << "Managing Director  :    +92 67xxxxxxxx" << std::endl;
  std::cout << "Executive Officer  :    +92 67xxxxxxxx" << std::endl;
  std::cout <<endl<< "Wisit : www.xtb.org " << std::endl;
}
void accountInformation()
{
  string globalName , globalPassword;
  cout <<endl<< "\033[33m" << "\t\tAccount Information" << "\033[0m" << endl<<endl;
  ifstream fin("Login.txt");
  if (!fin) {
    cerr<<"Error opening file!"<<endl;
    return;
  }

  getline(fin, globalName, ',');
  getline(fin, globalPassword);
  fin.close();
  std::cout << "Account Name: "<<globalName << std::endl;
  std::cout << "Account Password: "<<globalPassword << std::endl;
  std::cout << "Successive Transactions: "<<numberOfSuccessiveTransactions << std::endl;
  std::cout << "Failed Transactions: "<<numberOfFailedTransactions << std::endl;
}

string choice()
{
  string ch;
  cout<<"1. Check Amount\t\t\t2. Withdraw"<<endl;
  cout<<"3. Deposit Amount\t\t4. Transaction"<<endl;
  cout<<"5. Pay Special\t\t\t6. Benevolent Funds"<<endl;
  cout<<"7. Bonus\t\t\t8. Fee Submittion"<<endl;
  cout<<"9. Bank Privacy & Policy\t10. Customer Support"<<endl;
  cout<<"11. Account Information\t\t12. Logout"<<endl<<endl;
  cout<<"Enter Your Choice : ";
  cin>>ch;
  cout<<endl;
  return ch;
}


//accounts

void login(bool &log)
{
  string name, password;
  ifstream fin("Login.txt");
  if (!fin) {
    cerr<<"Error opening file!"<<endl;
    return;
  }

  getline(fin, name, ',');
  getline(fin, password);
  fin.close();

  cin.ignore(10,'\n');
  cout<<endl<<"**********************************************";
  cout<<endl<<"*****************Login Portal*****************";
  cout<<endl<<"**********************************************";
  string userName , userPass;
  //cout<<endl<<endl<<"Press any Key to Continue: ";
  this_thread::sleep_for(chrono::milliseconds(1000));
  loginLabel:
  cout<<"\n\nPlease Enter Account Name: ";
  //cin.ignore();
  getline(cin , userName);
  cout<<"\nPlease Enter Account Password: ";getline(cin , userPass);

  if (userName == name && userPass == password)
  {
    std::cout << "\nLogin Successful! " << std::endl;
    log = true;
  }
  else {
    std::cout << "\nInvalid Credentials! " << std::endl;
    goto loginLabel;
  }
  

  // cout<< "Separated Name is: " << name << endl;
  // cout<< "Separated Password is: " << password << endl;
}


void createAccount()
{
  string name , password;
  ofstream ot;
  nameLabel:
  cin.ignore();
  cout<<"\n\nEnter Account Name: ";getline(cin , name);
  //globalName = name;
  passwordLabel:
  cout<<"\n\nEnter Account Password: ";getline(cin , password);
  //globalPassword = password;
  if (name == "" || name.size()<3)
  {
    cout<<"\nPlease Enter Valid Name!\n";
    goto nameLabel;
  }
  else if (password.size()<7)
  {
    cout<<"\nWeak Password Strength!!\n";
    goto passwordLabel;
  }
  else
  {
    ot.open("Login.txt");
    ot<<name<<","<<password<<endl;
    ot.close();
    cout<<"\n\t\tAccount Created Successfully\n";

  }
}


void accountHandeling(bool &log)
{
  log = false;
  int choice;
  HYTfailLabel:
  std::cout << "1. Create an New Account\t\t2. Login";
  accountHandelingLabel:
  cout<<endl<<"Enter Your Choice: ";
  cin>>choice;
  if(cin.fail()){
    cin.clear();
    cin.ignore(10000,'\n');
    cout<<"You Entered Character instead of Int , Try Again .\n";

    goto HYTfailLabel;

  }
  if (choice == 1)
  {
    createAccount();
    //cin.ignore();
    cout<<endl;
    this_thread::sleep_for(chrono::milliseconds(1500));
    login(log);
  }
  else if (choice == 2)
  {
    login(log);
  }
  else{
    cout <<endl<< "\033[41m" << "Invalid Inputs" << "\033[0m" << endl;
    goto accountHandelingLabel;
  }
}

void logout()
{
  //std::cout <<endl<< "User logged Out Successfully! " << std::endl<<endl;
  std::cout <<endl<< "\033[43m" << "User logged Out Successfully!!" << "\033[0m" << endl;
}

int main()
{
  newLogoutLabel:
  bool log;
  welcome();
  accountHandeling(log);
  double amount = 0;
  char character;
  if (log == true)
  {
    do
    {
      menuResetLabel:
      cout<<endl<<endl;
      string ch = choice();

      if (ch == "1")
      {
        checkAmount(amount);
      }
      else if (ch == "2")
      {
        withdraw(amount);
      }
      else if (ch == "3")
      {
        deposit(amount);
      }
      else if (ch == "4")
      {
        transaction(amount);
      }
      else if (ch == "5")
      {
        paySpecial(amount);
      }
      else if (ch == "6")
      {
        benevolent(amount);
      }
      else if (ch == "7")
      {
        bonus(amount);
      }
      else if (ch == "8")
      {
        feeSubmittion(amount);
      }
      else if (ch == "9")
      {
        privacyAndPolicy();
      }
      else if (ch == "10")
      {
        customerSupport();
      }
      else if (ch == "11")
      {
        accountInformation();
      }
      else if (ch == "12")
      {
        logout();
        std::cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        //accountHandeling(log);
        goto newLogoutLabel;
      }
      else {
        cout<<"\n\"Invalid Inputs! Enter (1 - 9)\""<<endl<<endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        goto menuResetLabel;
      }
      std::cout << "\n Again Proceed (Y/N):";
      cin>>character;
      //cout<<endl<<character;
    } while (character=='y' || character=='Y');

    //cout<<endl<<"Thank You for Using our Banking Service";
    if (character == 'n' || character =='N')
    {
      cout<<endl<<"Thank You for Availing our Banking Service";
      this_thread::sleep_for(chrono::milliseconds(2000));
      //goto menuResetLabel;
      return 0;
    }
    else cout<<"\n\"Invalid Inputs!!\""<<endl<<endl;
  }
  
  
  return 0;
};

// {
//   std::cout <<endl<< "User logged Out Successfully! " << std::endl<<endl;
//   goto u;
// }