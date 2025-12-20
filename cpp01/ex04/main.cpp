#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	size_t pos;
	std::string filename;
	std::string s1;
	std::string s2;
	std::string line;
	std::string content;
	if (argc != 4)
	{
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std:: endl;
		return (1);		
	}
	pos = 0;
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Argument Error!" << std:: endl;
		return (1);
	}
	else
	{
		std::ifstream input_file(filename.c_str());
		if (!input_file)
		{
			std::cout << "Error: Could not open file!" << std::endl;
			return (1);
		}
		while (std::getline(input_file, line))
		{
			content = content + line;
			content = content + '\n';
		}
		input_file.close();
		while ((pos = content.find(s1, pos)) != std::string::npos)
		{
			content.erase(pos, s1.length());
			content.insert(pos, s2);
			pos += s2.length();
		}
		std::string new_filename;
		new_filename = filename + ".replace";
		std::ofstream output_file(new_filename.c_str());
		if (!output_file)
		{
			std::cout << "Error: Could not write" << std::endl;
			return (1);
		}
		output_file << content;
		output_file.close();
	}
	return (0);
}