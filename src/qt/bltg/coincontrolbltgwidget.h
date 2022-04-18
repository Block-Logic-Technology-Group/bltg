// Copyright (c) 2019 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLBLTGWIDGET_H
#define COINCONTROLBLTGWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlBltgWidget;
}

class CoinControlBltgWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlBltgWidget(QWidget *parent = nullptr);
    ~CoinControlBltgWidget();

private:
    Ui::CoinControlBltgWidget *ui;
};

#endif // COINCONTROLBLTGWIDGET_H
