import java.util.Properties;
import javax.mail.*;
import javax.mail.internet.*;
import javax.activation.*;

public class KYGMailClient {
    public static void main (String args[]) {
        if(args.length != 4) {
            System.out.println("usage : java <host> <from> <to> <filename>");
            System.exit(0); 
        }
        
        try {
            String host = args[0];
            String from = args[1];
            String to   = args[2];
            String filename = args[3];
            
            Properties props = System.getProperties();
            props.put("mail.smtp.host", host);
            Session session = Session.getInstance(props, null);
            Message message = new MimeMessage(session);
            message.setFrom(new InternetAddress(from));
            message.addRecipient(Message.RecipientType.TO, 
            new InternetAddress(to));
            message.setSubject("Attachments");
            BodyPart messageBodyPart = new MimeBodyPart();
            messageBodyPart.setText("Attachments mail");
            Multipart multipart = new MimeMultipart();
            multipart.addBodyPart(messageBodyPart);
            messageBodyPart = new MimeBodyPart();
            DataSource source = new FileDataSource(filename);
            messageBodyPart.setDataHandler(new DataHandler(source));
            messageBodyPart.setFileName(filename);
            multipart.addBodyPart(messageBodyPart);
            message.setContent(multipart);
            Transport.send(message);
        }
        catch(javax.mail.MessagingException e) {
            e.printStackTrace();
        }
    }
}