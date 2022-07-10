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

std::string replace_string(std::string file_name, std::string target, std::string replace)
{
	std::string line;
	std::string ret;
	std::ifstream ifs;

	ifs.open(file_name);
	if (ifs.fail())
		throw file_name + " open failed!";

	while (!ifs.eof())
	{
		std::getline(ifs, line);
		size_t idx = 0;
		while ((idx = line.find(target)) != std::string::npos)
		{
			ret += line.substr(0, idx) + replace;
			line.erase(0, idx + target.length());
		}
		ret += line + "\n";
	}
	ret = ret.substr(0, ret.size() - 1);
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