// Copyright (c) 2017-2019 The PIVX developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZBLTGCONTROLDIALOG_H
#define ZBLTGCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zbltg/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZBltgControlDialog;
}

class CZBltgControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZBltgControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZBltgControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZBltgControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZBltgControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZBltgControlDialog(QWidget *parent);
    ~ZBltgControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZBltgControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZBltgControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZBLTGCONTROLDIALOG_H
