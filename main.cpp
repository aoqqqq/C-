/*
*  ��д:-����-
*/

#include<iostream>
#include<vector>
#include<filesystem>
#include<fstream>
#include<string>

#define num_null -1
/// <summary>
/// ��ȡû�г��ȵĳ���
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
/// �ж���ͬ���� �ļ�������������ͬ
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <returns>������ͬ��Ԫ��</returns>
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
				std::cout << "rt=:" << A[i] << "��" << B[i2] << "��ͬ" << std::endl;
			}
		}
	}

	std::cout << "---------------------------------------------\n" << "��ͬ:" << rt.size() << "\n";
	for (size_t i = 0; i < rt.size(); i++)
	{
		std::cout << rt[i] << "\n";
	}

	std::cout << "---------------------------------------------\n" << "��ͬ:" << rt.size()<< "\n";
	return rt;
}
/// <summary>
/// �жϲ�ͬ��Ԫ��
/// </summary>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="out_b">����B����ͬԪ�ػ�A����</param>
/// <param name="indx">ûʵ�������</param>
/// <returns>����A����ͬԪ�ػ�A����</returns>
std::vector<std::string> not_butong(std::vector<std::string> A, std::vector<std::string> B, std::vector<std::string>& out_b,int &indx)
{
	std::vector<std::string> out_a;
	std::vector<std::string> t = xiangtong(A, B);
	if (t.size() == 0)
	{
		std::cout << "_______________________________________________________\n��ͬ:"<<"����ͬ" << std::endl;
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
		std::cout << "_______________________________________________________\n��ͬ:" << out_b.size() << std::endl;
		return out_a;
	}



}


/// <summary>
/// �����Ա��� �ظ����ֵ����滻�ļ� ��ͬ�Ͳ����滻
/// </summary>
/// <param name="file"></param>
/// <param name="outfilenames"></param>
void  bianli(std::string file, std::vector<std::string>& outfilenames)
{

	int i11 = 0;
	int lengths = length(std::filesystem::directory_iterator(file));
	std::cout << lengths <<"�ļ�" << "\n";
	std::vector<std::string> str;
	std::vector<std::string> phSS;
	std::vector<std::string> outname, outphss;
	std::vector<int> indx;
	for (auto i : std::filesystem::directory_iterator(file))
	{

		std::string strname = file ;
		strname += "�������";
		strname += std::to_string(i11);
		strname += ".jpg";

		str.push_back(i.path().string());
		phSS.push_back(strname);
		outfilenames.push_back(strname);
		i11++;
	}

	//�ȴ��� ������������� �����ص������ļ���ʧ
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
/// ���޸������Ϣ·��д�뵽 ָ���ļ�
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
			//neg.txt����Ҫ1 0 0 20 20
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