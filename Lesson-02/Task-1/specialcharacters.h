#ifndef SPECIAL_CHARACTERS_H
#define SPECIAL_CHARACTERS_H


#include <QMap>
#include <QString>

class SpecialCharacters
{
public:
    SpecialCharacters();
    ~SpecialCharacters() = default;

    QString replace(QString text) const;

private:
    QMap<QString, QString> replacements_;
};

#endif // SPECIAL_CHARACTERS_H
