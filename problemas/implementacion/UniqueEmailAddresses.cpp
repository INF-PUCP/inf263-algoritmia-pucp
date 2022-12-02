class Solution {
public:
  const char AT_SIGN = '@';
  set<string> unique_emails;
  
  string GetEmail(const string& email) {
    int at_sign = -1;
    int len = (int) email.size();
    for (int i = 0; i < len; i++) {
      if (email[i] == AT_SIGN) {
        at_sign = i;
        break;
      }
    }
    string local_name, domain_name;
    local_name = domain_name = "";
    for (int i = 0; i < at_sign; i++) {
      if (email[i] == '+') break;
      if (email[i] == '.') continue;
      local_name += email[i];
    }
    domain_name = email.substr(at_sign + 1, len - at_sign - 1);
    return local_name + AT_SIGN + domain_name;
  }
  
  int numUniqueEmails(vector<string>& emails) {
    int len = (int) emails.size();
    for (int i = 0; i < len; i++) {
      unique_emails.insert(GetEmail(emails[i]));
    }
    return (int) unique_emails.size();
  }
};