#include "pch.h"
#include "Account.h"
#include "User.h"

namespace py = pybind11;
using namespace Finance_Management;
using namespace util;

PYBIND11_MODULE(finance_module, m) {
    py::class_<Transaction>(m, "Transaction")
        .def(py::init<int, const util::Date&, const std::string&, double, const std::string&, const std::string&>())
        .def("getTransactionId", &Transaction::getTransactionId)
        .def("getDescription", &Transaction::getDescription)
        .def("getAmount", &Transaction::getAmount)
        .def("getTransactionType", &Transaction::getTransactionType)
        .def("getCategory", &Transaction::getCategory)
        .def("setDescription", &Transaction::setDescription)
        .def("setAmount", &Transaction::setAmount)
        .def("setTransactionType", &Transaction::setTransactionType)
        .def("setCategory", &Transaction::setCategory);

    py::class_<Date>(m, "Date")
        .def(py::init<>())  // Default constructor
        .def(py::init<int, int, int>())  // Constructor with day, month, and year
        .def("asgDate", &Date::asgDate)
        .def("ajouteNbJour", &Date::ajouteNbJour)
        .def("reqJour", &Date::reqJour)
        .def("reqMois", &Date::reqMois)
        .def("reqAnnee", &Date::reqAnnee)
        .def("reqJourDeAnnee", &Date::reqJourDeAnnee)
        .def("reqDateFormatee", &Date::reqDateFormatee)
        .def("__eq__", &Date::operator==)
        .def("__lt__", &Date::operator<)
        .def("__sub__", &Date::operator-)
        .def_static("estBissextile", &Date::estBissextile)
        .def_static("validerDate", &Date::validerDate)
        .def("__repr__", [](const Date& d) {
        return "<Date(" + std::to_string(d.reqJour()) + "/" + std::to_string(d.reqMois()) + "/" + std::to_string(d.reqAnnee()) + ")>";
            });

    // Exposing Account class
    py::class_<Account>(m, "Account")
        .def(py::init<int, const std::string&, const std::string&, double, const std::string&>())
        .def("getAccountId", &Account::getAccountId)
        .def("getAccountName", &Account::getAccountName)
        .def("getAccountType", &Account::getAccountType)
        .def("getBalance", &Account::getBalance)
        .def("getCurrency", &Account::getCurrency)
        .def("setAccountName", &Account::setAccountName)
        .def("setAccountType", &Account::setAccountType)
        .def("setBalance", &Account::setBalance)
        .def("setCurrency", &Account::setCurrency)
        .def("__str__", &Account::accountFormat)
        .def("__eq__", &Account::operator==)
        .def("__lt__", &Account::operator<)
        .def("__gt__", &Account::operator>)
        .def("__le__", &Account::operator<=)
        .def("__ge__", &Account::operator>=)
        .def("__ne__", &Account::operator!=)
        .def("verifieInvariant", &Account::verifieInvariant)
        .def("__repr__", [](const Account& a) {
        return "<Account id=" + std::to_string(a.getAccountId()) + " name=" + a.getAccountName() + ">";
            });

    // Exposing User class
    py::class_<User>(m, "User")
        .def(py::init<int, const std::string&, const std::string&, const std::string&>())
        .def("getUserId", &User::getUserId)
        .def("getUserName", &User::getUserName)
        .def("getPasswordHash", &User::getPasswordHash)
        .def("getEmail", &User::getEmail)
        .def("setUserName", &User::setUserName)
        .def("setPasswordHash", &User::setPasswordHash)
        .def("setEmail", &User::setEmail)
        .def("addAccount", &User::addAccount)
        .def("removeAccount", &User::removeAccount)
        .def("accountPresent", &User::accountPresent)
        .def("__str__", &User::userFormat)
        .def("__eq__", &User::operator==)
        .def("__lt__", &User::operator<)
        .def("__gt__", &User::operator>)
        .def("__le__", &User::operator<=)
        .def("__ge__", &User::operator>=)
        .def("__ne__", &User::operator!=)
        .def("getAccounts", &User::getAccounts)
        .def("verifieInvariant", &User::verifieInvariant)
        .def("__repr__", [](const User& u) {
        return "<User id=" + std::to_string(u.getUserId()) + " name=" + u.getUserName() + ">";
            });
    // Optionally expose friend function operator<< for printing
    m.def("print_date", [](const Date& d) {
        std::ostringstream oss;
        oss << d;
        return oss.str();
        });

}
