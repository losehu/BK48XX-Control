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
    ui->REG_TABLE->setColumnCount(5);
    ui->REG_TABLE->horizontalHeader()->setStretchLastSection(true);
    ui->REG_TABLE->setHorizontalHeaderLabels(QStringList()<<QString::fromLocal8Bit("DIR")<<QString::fromLocal8Bit("Name")<<QString::fromLocal8Bit("Bits")<<QString::fromLocal8Bit("Value")<<QString::fromLocal8Bit("Description"));
    ui->REG_TABLE->setRowCount(16);

  ui->REG_TABLE->verticalHeader()->setVisible(false);

}



/**
 * @brief REG_LIST::REG_RENAME
 * @param index
 * @param number
 * REG_RENAME(0, 0x12,"power")
 * 给第0个list命名为REG_00 0x12 power
 */
void REG_LIST::REG_RENAME(int index, uint16_t number, const QString& suffix) {
    if (index >= 0 && index < ui->REG_LIST->count()) {
        QListWidgetItem *item = ui->REG_LIST->item(index);
        if (item) {
              QString newName = QString("REG_%1 0x%2 %3")
                                .arg(index, 2, 16, QLatin1Char('0'))   // 确保index是两位数
                                .arg(number, 4, 16, QLatin1Char('0'))  // 将number格式化为4位16进制数
                                .arg(suffix);  // 添加自定义字符串
              item->setText(newName);
          }
    }
}

