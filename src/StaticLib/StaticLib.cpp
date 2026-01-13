#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	if (begin == nullptr || end == nullptr) 
	{
		return false;
	}
	if (begin >= end) 
	{
		return false;
	}
	size_t length = end - begin;
	if (length <= 1) 
	{
		return true;
	}

	item pivot = begin[length / 2];
	item* left = begin;
	item* right = (item*)end - 1;

	while (left <= right)
	{
		while (left->key < pivot.key)
		{
			left++;
		}
		while (right->key > pivot.key)
		{
			right--;
		}
		if (left <= right)
		{
			item temp = *left;
			*left = *right;
			*right = temp;

			left++;
			right--;
		}
	}

	quick_sort(begin, right + 1);
	quick_sort(left, end);

	return true;
}
