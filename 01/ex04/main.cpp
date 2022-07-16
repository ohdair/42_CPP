/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:21:57 by jaewpark          #+#    #+#             */
/*   Updated: 2022/07/10 14:42:16 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string _replace_newLine(std::string target)
{
	std::string ret;
	size_t idx;

	while ((idx = target.find("\\n")) != std::string::npos)
	{
		ret += target.substr(0, idx) + "\n";
		target.erase(0, idx + 2);
	}
	ret += target;
	return ret;
}

std::string replace_string(std::string file_name, std::string target, std::string replace)
{
	std::string line;
	std::string allLine;
	std::string ret;
	std::ifstream ifs;
	std::string newTarget(_replace_newLine(target));
	std::string newReplace(_replace_newLine(replace));

	ifs.open(file_name);
	if (ifs.fail())
		throw file_name + " open failed!";

	while (!ifs.eof())
	{
		std::getline(ifs, line);
		allLine += line + "\n";
	}
	allLine = allLine.substr(0, ret.size() - 1);
	size_t idx = 0;
	while ((idx = allLine.find(newTarget)) != std::string::npos)
	{
		ret += allLine.substr(0, idx) + newReplace;
		allLine.erase(0, idx + newTarget.length());
	}
	ret += allLine;
	ifs.close();
	return (ret);
}

int	main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "\e[31mError : Program needs 3 arguments\e[0m\nUsage : ./ReplaceString filename, string1, string2" << std::endl;
		return 1;
	}

	std::string file_name(argv[1]);
	std::string target(argv[2]);
	std::string replace(argv[3]);
	std::string input;

	try {
		input = replace_string(file_name, target, replace);
	} catch (std::string exception) {
		std::cerr << exception << std::endl;
		return (1);
	}
	
	std::ofstream ofs(file_name + ".replace");
	if (ofs.fail())
	{
		std::cerr << file_name << ".replace open failed!" << std::endl;
		return 1;
	}
	ofs << input;
	ofs.close();

	return 0;
}