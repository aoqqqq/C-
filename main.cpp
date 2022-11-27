/*
*  编写:-傲奇-
*/

#include<iostream>
#include<vector>
#include<filesystem>
#include<fstream>
#include<string>

#define num_null -1
/// <summary>
/// 获取没有长度的长度
/// </summary>
/// <param name="o"></param>
/// <returns></returns>
int length(auto o)
{
	int i = 0;
	for (auto i1 : o)
	{
		i++;
	}
	return i;
}
/// <summary>
/// 判断相同数量 文件与所需名字相同
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <returns>返回相同的元素</returns>
std::vector<std::string> xiangtong(std::vector<std::string> A, std::vector<std::string> B)
{
	std::vector<std::string> rt;
	for (size_t i = 0; i < A.size(); i++)
	{
		for (size_t i2 = 0; i2 < B.size(); i2++)
		{
			if (A[i] == B[i2])
			{
				rt.push_back(A[i]);
				std::cout << "rt=:" << A[i] << "与" << B[i2] << "相同" << std::endl;
			}
		}
	}

	std::cout << "---------------------------------------------\n" << "相同:" << rt.size() << "\n";
	for (size_t i = 0; i < rt.size(); i++)
	{
		std::cout << rt[i] << "\n";
	}

	std::cout << "---------------------------------------------\n" << "相同:" << rt.size()<< "\n";
	return rt;
}
/// <summary>
/// 判断不同的元素
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="out_b">返回B的相同元素或A本身</param>
/// <param name="indx">没实现随便填</param>
/// <returns>返回A的相同元素或A本身</returns>
std::vector<std::string> not_butong(std::vector<std::string> A, std::vector<std::string> B, std::vector<std::string>& out_b,int &indx)
{
	std::vector<std::string> out_a;
	std::vector<std::string> t = xiangtong(A, B);
	if (t.size() == 0)
	{
		std::cout << "_______________________________________________________\n不同:"<<"都不同" << std::endl;
		out_b = B;
		return A;
	}
	else
	{
		for (size_t i = 0; i < A.size(); i++)
		{
			size_t next = num_null;
			for (size_t i2 = 0; i2 < t.size(); i2++)
			{
				if (A[i] == t[i2])
				{
					next = num_null;
					break;
				}
				else
				{
					if (next == num_null)
					{
						next = 0;
					}
					next++;
				}
			}
			if (next != num_null)
			{
				out_a.push_back(A[i]);
			}

		}
		for (size_t i = 0; i < B.size(); i++)
		{
			size_t next = num_null;
			for (size_t i2 = 0; i2 < t.size(); i2++)
			{
				if (B[i] == t[i2])
				{
					next = num_null;
					break;
				}
				else
				{
					if (next == num_null)
					{
						next = 0;
					}
					next++;
				}
			}
			if (next != num_null)
			{
				out_b.push_back(B[i]);
			}

		}
		std::cout << "_______________________________________________________\n不同:" << out_b.size() << std::endl;
		return out_a;
	}



}


/// <summary>
/// 它可以避免 重复名字导致替换文件 相同就不会替换
/// </summary>
/// <param name="file"></param>
/// <param name="outfilenames"></param>
void  bianli(std::string file, std::vector<std::string>& outfilenames)
{

	int i11 = 0;
	int lengths = length(std::filesystem::directory_iterator(file));
	std::cout << lengths <<"文件" << "\n";
	std::vector<std::string> str;
	std::vector<std::string> phSS;
	std::vector<std::string> outname, outphss;
	std::vector<int> indx;
	for (auto i : std::filesystem::directory_iterator(file))
	{

		std::string strname = file ;
		strname += "名字随便";
		strname += std::to_string(i11);
		strname += ".jpg";

		str.push_back(i.path().string());
		phSS.push_back(strname);
		outfilenames.push_back(strname);
		i11++;
	}

	//先打乱 再填充有序名称 避免重叠导致文件消失
	//for (size_t i = 0; i < lengths; i++)
	//{
	//	std::string s = file + std::to_string(i);
	//	std::filesystem::rename(str[i], s);
	// str[i] = s;
	//}
	//for (size_t i = 0; i < str.size(); i++)
	//{
	//	size_t i1 = 0;
	//	size_t i3 = -1;

	//	size_t nullindx = -1;
	//	for (size_t i2 = 0; i2 < phSS.size(); i2++)
	//	{

	//		if (indx.size() > 0)
	//		{
	//			if (i1 < indx.size())
	//			{
	//				if (indx[i1] == i2)
	//				{

	//					i1++;
	//					continue;
	//				}

	//			}

	//		}
	//		if (str[i] == phSS[i2])
	//		{
	//			indx.push_back(i2);
	//			break;
	//		}
	//		else
	//		{
	//			i3++;
	//			if (nullindx == -1)
	//			{
	//				nullindx = i2;
	//			}

	//		}


	//	}
	//	if (i3 !=-1)
	//	{
	//		if (nullindx != -1)
	//		{
	//			std::filesystem::rename(str[i], phSS[nullindx]);
	//		}

	//	}
	//}

	std::vector<std::string> outphsss;
	int a = 0;
	std::vector<std::string> outstr = not_butong(str, phSS, outphsss,a);
	for (size_t i = 0; i < outstr.size(); i++)
	{
		std::cout << outstr[i] << "\tT" << outphsss[i] << std::endl;
		std::filesystem::rename(outstr[i], outphsss[i]);
	}




}

/// <summary>
/// 将修改完的信息路径写入到 指定文件
/// </summary>
/// <param name="file"></param>
/// <param name="wstrarray"></param>
/// <param name="t"></param>
void io(std::string file, std::vector<std::string> wstrarray,bool t)
{
	std::ofstream output;
	output.open(file, std::ios::ate);


	if (t)
	{
		for (size_t i = 0; i < wstrarray.size(); i++)
		{

			std::cout << wstrarray[i] << std::endl;
			//neg.txt不需要1 0 0 20 20
			output << wstrarray[i] << std::endl;

		}
	}
	else
	{
		for (size_t i = 0; i < wstrarray.size(); i++)
		{

			std::cout << wstrarray[i] << std::endl;
			output << wstrarray[i] << std::endl;

		}
	}
	

	output.close();
}


int main()
{


	std::vector<std::string> strarry;
	bianli("E:\\ml\\flower_photos\\flower_photos\\dandelion\\", strarry);
	for (size_t i = 0; i < strarry.size(); i++)
	{

		std::cout << strarry[i] << "\n";
	}
	io("E:\\cv\\train\\train\\neg.txt", strarry,true);
	return 0;
}