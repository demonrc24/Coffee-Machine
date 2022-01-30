#include "functions.h" // 自己的函数头文件
#include "structs.h" // 自己的结构体头文件

//子菜单，直接引用即可
//由于可能会有引用问题，下级子菜单放在上方

//------------------------------------------------------------------------
//三级子菜单

//新增订单
void add_order() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("-------------------新增订单-------------------\n");
    std::printf("[0] 选择菜单 [1] 自定义菜单 [9] 返回主界面\n");
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {

      case 0:
	add_preset_order();
	break;
      case 1:
	add_custom_order();
	break;

      default:
	std::printf("未完成，请返回上一级\n");
	break;
    }
    press_any_button_1();
  }
}

//打印预设菜单
void print_preset_menu() {
  system_status();
  for (auto i = machine_menus.begin(); i != machine_menus.end(); i++) {
    print_line();
    print_coffee_menu(*i);
  }
  press_any_button_1();
}

void delete_drink_menu() {
  std::string menu_name;
  bool flag = false;
  int num;
  do {
    num = 1;
    for (auto i = machine_menus.begin(); i != machine_menus.end(); i++) {
      std::cout << num << '.' << i->name << std::endl;
      num++;
    }
    std::cout << "请输入您想要移除的菜单名称。" << std::endl;
    std::cout << "注意：不能输入编号！！！" << std::endl;
    std::cin >> menu_name;
    delete_menu(menu_name);
    std::cout << "您还需要继续删除其他菜单吗？" << std::endl;
    flag = input_bool();
  }
  while (flag);
}

//添加其他原料子菜单
void add_other_ingredient() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("-------------------其他原料-------------------\n");
    std::printf("[0] 奶制品 [1] 糖浆 [2] 甜味剂 [3] 酒 [4] 其他原料 [9] 返回上一级\n");
    std::cout << "请注意，所有的数据均按照质量计算。" << std::endl;
    std::cout << "数值对应为原料的克数，即当前有多少克原料。" << std::endl;
    print_line();
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 0:
	input_milk(machine_ingredients.additives);
	break;
      case 1:
	input_syrup(machine_ingredients.additives);
	break;
      case 2:
	input_sweeter(machine_ingredients.additives);
	break;
      case 3:
	input_alcohol(machine_ingredients.additives);
	break;
      case 4:
	input_other_ingredient(machine_ingredients.additives);
	break;
      default:
	std::printf("输入错误，请重新输入：\n");
	break;
    }
    press_any_button_1();
  }
}

//------------------------------------------------------------------------
//二级子菜单

//原料资源管理子菜单

//添加新原料
void add_ingredient() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("------------------添加新原料------------------\n");
    std::printf("[0] 添加水 [1] 添加咖啡豆 [2] 添加其他原料 [9] 返回上一级\n");
    std::cout << "请注意，所有的数据均按照质量计算。" << std::endl;
    std::cout << "数值对应为原料的克数，即当前有多少克原料。" << std::endl;
    print_line();
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 0:
	std::cout << "请输入咖啡机内当前的水量。" << std::endl;
	input_value(machine_ingredients.water);
	break;
      case 1:
	std::cout << "请输入咖啡机内当前的咖啡豆数量。" << std::endl;
	input_value(machine_ingredients.coffeeBean);
	break;
      case 2:
	add_other_ingredient();
	break;
      default:
	std::printf("输入错误，请重新输入：\n");
	break;
    }
    press_any_button_1();
  }
}

//删除原料
void delete_ingredient() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("---------------选择删除原料类型---------------\n");
    std::printf("[0] 奶制品 [1] 糖浆 [2] 甜味剂 [3] 酒 [4] 其他原料 [9] 返回上一级\n");
    print_line();
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 0:
	delete_milk(machine_ingredients.additives);
	break;
      case 1:
	delete_syrup(machine_ingredients.additives);
	break;
      case 2:
	delete_sweeter(machine_ingredients.additives);
	break;
      case 3:
	delete_alcohol(machine_ingredients.additives);
	break;
      case 4:
	delete_other_ingredient(machine_ingredients.additives);
	break;
      default:
	std::printf("输入错误，请重新输入：\n");
	break;
    }
    press_any_button_1();
  }
}

//------------------------------------------------------------------------
//一级子菜单

//原料资源管理
void ingredient_management() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("-------------------原料管理-------------------\n");
    std::printf("[0] 添加原料 [1] 删除原料 [2] 现有原料列表 [9] 返回主界面\n");
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 0:
	add_ingredient();
	break;
      case 1:
	delete_ingredient();
	break;
      case 2:
	print_machine_ingredients();
	break;
      default:
	std::printf("输入错误，请重新输入：\n");
	break;
    }
    press_any_button_1();
  }
}

//预设菜单管理
void menu_management() {
  int button = 10;
  while (true) {
    system_status();
    std::printf("-------------------菜单管理-------------------\n");
    std::printf("[0] 添加新菜单 [1] 删除菜单 [9] 返回主界面\n");
    std::cin >> button;
    if (button == 9)
      break;
    switch (button) {
      case 0:
	add_new_coffee_menu();
	break;
      case 1:
	delete_drink_menu();
	break;
      default:
	std::printf("未完成，请返回上一级\n");
	break;
    }
    press_any_button_1();
  }
}

