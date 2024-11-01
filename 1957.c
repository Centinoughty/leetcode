char* makeFancyString(char* s) {
  int n = strlen(s);
  char* t = (char*)malloc((n + 1) * sizeof(char));
  int pos = 0;
  char a = '\n';
  char b = '\n';

  for (int i = 0; s[i]; i ++) {
    if (!(a == b && b == s[i])) {
      t[pos ++] = s[i];
    }

    a = b;
    b = s[i];
  }

  t[pos] = '\0';
  return t;
}