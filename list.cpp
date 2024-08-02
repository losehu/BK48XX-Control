#include "list.h"

/**
 * @brief REG_LIST::REG_LIST
 * @param p
 * 初始化
 */
REG_LIST::REG_LIST(Ui::MainWindow * p):
    ui(p)
{
    //初始化list名称为REG_00~REG_{MAX_REG_NUM}
    for (int i = 0; i <= MAX_REG_NUM; ++i) {
        QString itemText = QString("REG_%1").arg(i, 2, 16, QLatin1Char('0')).toUpper();
        ui->REG_LIST->addItem(itemText);
    }
    //初始化list选中第一项
    ui->REG_LIST->setCurrentRow(1);
}



/**
 * @brief REG_LIST::REG_RENAME
 * @param index
 * @param number
 * REG_RENAME(0, 0x12)
 * 给第0个list命名为REG_00 0x12
 */
void REG_LIST::REG_RENAME(int index, uint16_t number) {
    if (index >= 0 && index < ui->REG_LIST->count()) {
        QListWidgetItem *item = ui->REG_LIST->item(index);
        if (item) {
              QString newName = QString("REG_%1 0x%2")
                                .arg(index, 2, 16, QLatin1Char('0'))   // 确保N是两位数
                                .arg(number, 4, 16, QLatin1Char('0'))  // 将number格式化为8位16进制数
                                .toUpper();
              item->setText(newName);
          }
    }
}
