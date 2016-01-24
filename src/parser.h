#ifndef SPARROW_PARSER_H_
#define SPARROW_PARSER_H_

#include <set>
#include <map>
#include <string>
#include "parser_constructor.h"

/*语法规则：
 * param      : IDENTIFIER
 * params     : param {"," param}
 *              | NULL
 * param_list : "(" params ")"
 * primary    : "lamb" param_list block
 *              |("(" expr ")" | NUMBER | IDENTIFIER | STRING) {posifix}
 * factory    : "-" primary | primary
 * expr       : factor { OP factor }
 * block      : "{" [statement] {(";" | EOL) [statement]} "}"
 * def        : "def" IDENTIFIER param_list block
 * args       : expr {"," expr}
 *              | NULL
 * postfix    : "(" args ")"
 * simple     : expr
 * statement  : "if" expr block ["else" block]
 *              | "while" expr block
 *              | simple
 * program    : [def | statement] (";" | EOL)
 */

class BasicParser {
public:
  BasicParser(); 

  //初始化函数，构造解析逻辑
  //只有初始化之后才能工作
  void init();

  //解析并生成抽象语法树
  ASTreePtr parse(Lexer &lexer);

private:
  //初始化保留字
  void initReserved();

  //初始化操作符
  void initOperators();

private:
  std::set<std::string> reserved_;
  std::map<std::string, Precedence> operators_;

  ParserPtr program_;
};

#endif