//exception launched on any error related to account.
class AccountException extends RuntimeException {
    public AccountException(String message) {
        super(message);
    }
}
