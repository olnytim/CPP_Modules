#include "ShrubberyCreationForm.hpp"

#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 25, 5) {}

ShrubberyCreationForm::ShrubberyCreationForm(const string &target) : AForm("ShrubberyCreationForm", 25, 5) {
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &toCopy) : AForm(toCopy) {
	*this = toCopy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &toCopy) {
	if (this != &toCopy)
		AForm::operator=(toCopy);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char* ShrubberyCreationForm::OpenFileException::what() const throw() {
	return ("File was not opened!");
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (getSigned() == "false")
		throw AForm::FormNotSignedException();
	std::ofstream	fout;
	fout.open(getTarget() + "_shrubbery");
	if (!fout.is_open())
		throw ShrubberyCreationForm::OpenFileException();
	fout << "              _{\\ _{\\{\\/}/}/}__\n" \
			"             {/{/\\}{/{/\\}(\\}{/\\} _\n" \
			"            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n" \
			"         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n" \
			"        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n" \
			"       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n" \
			"      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n" \
			"      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n" \
			"     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n" \
			"      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n" \
			"       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n" \
			"      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n" \
			"       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n" \
			"         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n" \
			"          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n" \
			"            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n" \
			"             {/{\\{\\{\\/}/}{\\{\\\\}/}\n" \
			"              {){/ {\\/}{\\/} \\}\\}\n" \
			"              (_)  \\.-'.-/\n" \
			"          __...--- |'-.-'| --...__\n" \
			"   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n" \
			" -\"    ' .  . '    |.'-._| '  . .  'olnytim\n" \
			" .  '-  '    .--'  | '-.'|    .  '  . '\n" \
			"          ' ..     |'-_.-|\n" \
			"  .  '  .       _.-|-._ -|-._  .  '  .\n" \
			"              .'   |'- .-|   '.\n" \
			"  ..-'   ' .  '.   `-._.-�   .'  '  - .\n" \
			"   .-' '        '-._______.-'     '  .\n" \
			"        .      ~,\n" \
			"    .       .   |\\   .    ' '-.\n" \
			"    ___________/  \\____________\n" \
			"   /  Why is it, when you want \\\n" \
			"  |  something, it is so damn   |\n" \
			"  |    much work to get it?     |\n" \
			"   \\___________________________/" << endl;
	fout.close();
}
