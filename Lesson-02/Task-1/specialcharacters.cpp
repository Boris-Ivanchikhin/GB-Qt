#include "specialcharacters.h"

SpecialCharacters::SpecialCharacters()
{
    // Задаем соответствия между специальными символами и их заменами
    replacements_["@CR@"] = QString::fromUtf8("\u00A9"); // ©
    replacements_["@PM@"] = QString::fromUtf8("\u2030"); // ‰
    replacements_["@EURO@"] = QString::fromUtf8("\u20AC"); // €
    replacements_["@RUB@"] = QString::fromUtf8("\u20BD"); // ₽
}

QString SpecialCharacters::replace(QString text) const
{
    // Проходим по всем заменам и заменяем соответствующие подстроки в тексте
    for (auto it = replacements_.constBegin(); it != replacements_.constEnd(); ++it) {
        text.replace(it.key(), it.value());
    }
    return text;
}
