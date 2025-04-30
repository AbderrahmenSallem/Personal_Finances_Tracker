document.addEventListener("DOMContentLoaded", function () {
    document.getElementById("loginForm").addEventListener("submit", async function (event) {
        event.preventDefault(); // Prevent the default form submission behavior

        const formData = new FormData(event.target); // Collect form data

        try {
            const response = await fetch("/auth/login", {
                method: "POST",
                body: formData,
            });

            if (response.ok) {
                const result = await response.json();
                // Log the server's message
                console.log(result.message);

                // Display the flash message
                const flashContainer = document.getElementById("flash-messages");
                flashContainer.innerHTML = result.message;

                // Redirect if a redirect URL is provided
                if (result.redirect_url) {
                    window.location.href = result.redirect_url;
                }
            } else {
                const error = await response.json();
                console.error("Error:", error.message);

                // Display error message
                const flashContainer = document.getElementById("flash-messages");
                flashContainer.innerHTML = error.message;
            }
        } catch (error) {
            console.error("Fetch error:", error);
        }
    });
});
