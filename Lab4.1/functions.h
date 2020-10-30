#pragma once

void SetString(char*& str, size_t* length);
void AllTolower(char* str);
bool IsPalindrome(char* str);
void EraseSpace(char*& str);
void CopyArr(int* dest, int length, int* src);
int* Find(const char* str, const char* substr);
void Encrypt(char* str, int key);
void AllNames(const char* str);